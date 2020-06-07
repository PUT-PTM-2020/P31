/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "libraries.hpp"
#include "main.h"
#include "gpio.h"
#include "adc.h"
#include "dac.h"
#include "dma.h"
#include "tim.h"
#include "display.h"
#include "display.c"
#include "ff.h"

#include "Includes.hpp"
#include "joystick.hpp"
#include "screen.hpp"
#include <vector>
#include <string>
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
TIM_HandleTypeDef htim2;
int a = 0;		//debug variable
int b = 0;		//debug variable
int c = 0;		//debug variable
int d = 0;		//debug variable
int shotButton = 0;
int button1 = 0;
int button2 = 0;
int button3 = 0;
SPI_HandleTypeDef hspi1;

char buffer[256]; //bufor odczytu i zapisu
static FATFS FatFs; //uchwyt do urządzenia FatFs (dysku, karty SD...)
FRESULT fresult; //do przechowywania wyniku operacji na bibliotece FatFs
FIL file; //uchwyt do otwartego pliku
UINT bytes_written; //liczba zapisanych byte	WORD
UINT bytes_read; //liczba odczytanych byte		WORD
/*
DMA_InitTypeDef dma;
ADC_HandleTypeDef hadc3;
DAC_HandleTypeDef hdac;
TIM_HandleTypeDef htim4;
uint16_t value;
double napiecie;*/
//int i = 64138;
int i = 0;
extern const uint8_t rawData2[64138];
/*
int state1 = 0;
int state2 = 0;
int bK0 = 0;
int ib;*/
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/**
 * Sets Player coordinates
 *
 * ARG:
 * 	j - Joystick object
 * 	p - pointer to Player object
*/
void setXY(Joystick j, Player *p){
	if (j.valueX < 1000 && p->positionX > 0) p->positionX--;
	else if (j.valueX > 3000 && p->positionX < 84-p->getWidth()) p->positionX++;
	if (j.valueY < 1000 && p->positionY > 0) p->positionY--;
	else if (j.valueY > 3000 && p->positionY < 48-p->getHeight()) p->positionY++;
}

/**
 * Sets active SPI
 *
 * ARG:
 * 	display - display's state: 0 if inactive, 1 if active, anything else if does not change
 * 	SD - SD reader's state: 0 if inactive, 1 if active, anything else if does not change
*/
void setSPI(int display, int SD){
	if(display==0)
		HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, GPIO_PIN_SET);
	else if (display==1)
		HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, GPIO_PIN_RESET);
	if(SD==0)
		HAL_GPIO_WritePin(SD_CS_GPIO_Port, SD_CS_Pin, GPIO_PIN_SET);
	else if (SD==1)
		HAL_GPIO_WritePin(SD_CS_GPIO_Port, SD_CS_Pin, GPIO_PIN_RESET);
}

/* USER CODE END 0 */
/*
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
 if(htim->Instance == TIM4)
 {
	 HAL_ADC_Start(&hadc3);
	 	  if(HAL_ADC_PollForConversion(&hadc3, 10) == HAL_OK)
	 	  	  {
	 	  	   value = HAL_ADC_GetValue(&hadc3);
	 	  	  }
	 	  napiecie = value/1365.0;

	 	 HAL_DAC_SetValue(&hdac,DAC_CHANNEL_1,DAC_ALIGN_12B_R,(uint16_t)rawData2[i]*value/1000);
	 	 	 if(i<64138) i++;

	 HAL_DAC_Start_DMA (&hdac, DAC_CHANNEL_1,(uint32_t*)rawData2[i],128,DAC_ALIGN_12B_R);

 }
}
*/

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	Joystick j;
	Level l(true);

	l.Constructions.push_back(Construction(9, 32, 2));
	l.Constructions.push_back(Construction(34, 32, 2));
	l.Constructions.push_back(Construction(59, 32, 2));

	std::vector<std::pair<uint8_t,uint8_t>> moveVec0;
		 moveVec0.push_back(std::pair<uint8_t, uint8_t>(71, 0));
		 moveVec0.push_back(std::pair<uint8_t, uint8_t>(61, 0));

	std::vector<std::pair<uint8_t,uint8_t>> moveVec1;
		 moveVec1.push_back(std::pair<uint8_t, uint8_t>(59, 0));
		 moveVec1.push_back(std::pair<uint8_t, uint8_t>(49, 0));

	std::vector<std::pair<uint8_t,uint8_t>> moveVec2;
		 moveVec2.push_back(std::pair<uint8_t, uint8_t>(47, 0));
		 moveVec2.push_back(std::pair<uint8_t, uint8_t>(37, 0));

	std::vector<std::pair<uint8_t,uint8_t>> moveVec3;
		 moveVec3.push_back(std::pair<uint8_t, uint8_t>(35, 0));
		 moveVec3.push_back(std::pair<uint8_t, uint8_t>(25, 0));

	std::vector<std::pair<uint8_t,uint8_t>> moveVec4;
		 moveVec4.push_back(std::pair<uint8_t, uint8_t>(23, 0));
		 moveVec4.push_back(std::pair<uint8_t, uint8_t>(13, 0));

	 std::vector<std::pair<uint8_t,uint8_t>> moveVec5;
	 moveVec5.push_back(std::pair<uint8_t, uint8_t>(11, 0));
	 moveVec5.push_back(std::pair<uint8_t, uint8_t>(1, 0));
	  //----------------------------------
	 std::vector<std::pair<uint8_t,uint8_t>> b0;
	 		 b0.push_back(std::pair<uint8_t, uint8_t>(61, 8));
	 		 b0.push_back(std::pair<uint8_t, uint8_t>(71, 8));

	 	std::vector<std::pair<uint8_t,uint8_t>> b1;
	 		 b1.push_back(std::pair<uint8_t, uint8_t>(49, 8));
	 		 b1.push_back(std::pair<uint8_t, uint8_t>(59, 8));

	 	std::vector<std::pair<uint8_t,uint8_t>> b2;
	 		 b2.push_back(std::pair<uint8_t, uint8_t>(37, 8));
	 		 b2.push_back(std::pair<uint8_t, uint8_t>(47, 8));

	 	std::vector<std::pair<uint8_t,uint8_t>> b3;
	 		 b3.push_back(std::pair<uint8_t, uint8_t>(25, 8));
	 		 b3.push_back(std::pair<uint8_t, uint8_t>(35, 8));

	 	std::vector<std::pair<uint8_t,uint8_t>> b4;
	 		 b4.push_back(std::pair<uint8_t, uint8_t>(13, 8));
	 		 b4.push_back(std::pair<uint8_t, uint8_t>(23, 8));

	 	 std::vector<std::pair<uint8_t,uint8_t>> b5;
	 	 b5.push_back(std::pair<uint8_t, uint8_t>(1, 8));
	 	 b5.push_back(std::pair<uint8_t, uint8_t>(11, 8));
	 	 //-----------------------------------------
	 	std::vector<std::pair<uint8_t,uint8_t>> a0;
	 			 a0.push_back(std::pair<uint8_t, uint8_t>(71, 16));
	 			 a0.push_back(std::pair<uint8_t, uint8_t>(61, 16));

	 		std::vector<std::pair<uint8_t,uint8_t>> a1;
	 			 a1.push_back(std::pair<uint8_t, uint8_t>(59, 16));
	 			 a1.push_back(std::pair<uint8_t, uint8_t>(49, 16));

	 		std::vector<std::pair<uint8_t,uint8_t>> a2;
	 			 a2.push_back(std::pair<uint8_t, uint8_t>(47, 16));
	 			 a2.push_back(std::pair<uint8_t, uint8_t>(37, 16));

	 		std::vector<std::pair<uint8_t,uint8_t>> a3;
	 			 a3.push_back(std::pair<uint8_t, uint8_t>(35, 16));
	 			 a3.push_back(std::pair<uint8_t, uint8_t>(25, 16));

	 		std::vector<std::pair<uint8_t,uint8_t>> a4;
	 			 a4.push_back(std::pair<uint8_t, uint8_t>(23, 16));
	 			 a4.push_back(std::pair<uint8_t, uint8_t>(13, 16));

	 		 std::vector<std::pair<uint8_t,uint8_t>> a5;
	 		 a5.push_back(std::pair<uint8_t, uint8_t>(11, 16));
	 		 a5.push_back(std::pair<uint8_t, uint8_t>(1, 16));

	 l.Enemies.push_back(Enemy(1, 0, 1, true, moveVec5));
	 l.Enemies.push_back(Enemy(13, 0, 1, true, moveVec4));
	 l.Enemies.push_back(Enemy(25, 0, 1, true, moveVec3));
	 l.Enemies.push_back(Enemy(37, 0, 1, true, moveVec2));
	 l.Enemies.push_back(Enemy(49, 0, 1, true, moveVec1));
	 l.Enemies.push_back(Enemy(61, 0, 1, true, moveVec0));

	 l.Enemies.push_back(Enemy(11, 8, 1, true, b5));
	 l.Enemies.push_back(Enemy(23, 8, 1, true, b4));
	 l.Enemies.push_back(Enemy(35, 8, 1, true, b3));
	 l.Enemies.push_back(Enemy(47, 8, 1, true, b2));
	 l.Enemies.push_back(Enemy(59, 8, 1, true, b1));
	 l.Enemies.push_back(Enemy(71, 8, 1, true, b0));

	 l.Enemies.push_back(Enemy(1, 16, 1, true, a5));
	 l.Enemies.push_back(Enemy(13, 16, 1, true, a4));
	 l.Enemies.push_back(Enemy(25, 16, 1, true, a3));
	 l.Enemies.push_back(Enemy(37, 16, 1, true, a2));
	 l.Enemies.push_back(Enemy(49, 16, 1, true, a1));
	 l.Enemies.push_back(Enemy(61, 16, 1, true, a0));

	 //l.boss_ptr = new Boss();
	 l.player = Player(37, 40,3);

	 /**
	  * If true player has already shot.
	  * If false he hasn't.
	 */
	 //bool pShot = false;

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_SPI1_Init();
  MX_SPI2_Init();
  MX_TIM2_Init();
  MX_TIM4_Init();

  /* USER CODE BEGIN 2 */
  //HAL_TIM_Base_Start_IT(&htim2);

  setSPI(2, 0);

  	struct display_config cfg;
	cfg.spi = &hspi2;
	cfg.reset_port = RST_GPIO_Port;
	cfg.reset_pin = RST_Pin;
	cfg.bl_port = BL_GPIO_Port;
	cfg.bl_pin = BL_Pin;
	cfg.dc_port = DC_GPIO_Port;
	cfg.dc_pin = DC_Pin;
	cfg.ce_port = CE_GPIO_Port;
	cfg.ce_pin = CE_Pin;
	display_setup(&cfg);

	setSPI(0,1);

//TODO: Load Level file here

	setSPI(1,0);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  while (!l.finished()){
	  j.getJoystick();
	  setXY(j, &l.player);

	// shotButton = !HAL_GPIO_ReadPin(K0_GPIO_Port, K0_Pin);



	  button1 = !HAL_GPIO_ReadPin(K0_GPIO_Port, K0_Pin);
	  if (button1 == 1){
		  if (button2 == 0){
			  button2 = button1;
			  shotButton = 0;
		  }else if (button2 == 1){
			  if (button3 == 1)
				  shotButton = 1;
			  else button3 = 1;
		  }
	  }else{
		  button2 = 0;
		  button3 = 0;
		  shotButton = 0;
	  }

	  clear(cfg);

	  if (shotButton && l.playerShot==nullptr) {
		  if (l.playerShoot()) {

			 // i=0;
			 // HAL_TIM_Base_Start_IT(&htim4);
		  }
	  }
	  //HAL_TIM_Base_Stop_IT(&htim4);
	  l.play();
	  displayLevel(cfg, &l);

	  HAL_Delay(100);
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
