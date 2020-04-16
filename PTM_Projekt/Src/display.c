#include "display.h"

void display_setup(struct display_config * cfg)
{
    // Sprzŕtowy reset wyťwietlacza
    HAL_GPIO_WritePin(cfg->reset_port, cfg->reset_pin, GPIO_PIN_RESET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(cfg->reset_port, cfg->reset_pin, GPIO_PIN_SET);

    // W│╣czenie podťwietlenia
    HAL_GPIO_WritePin(cfg->bl_port, cfg->bl_pin, GPIO_PIN_SET);

    // Przejťcie w tryb polece˝ rozszerzonych
    // 0x00100001 (0x21) - polecenie
    display_write_cmd(cfg, 0x21);

    // Temperature Coefficient
    // 0b00000100 (0x04) - polecenie | 0b00000000 (0x00) - wartoťŠ
    // = 0b00000100 (0x04)
    display_write_cmd(cfg, 0x04);

    // Bias System
    // 0b00010000 (0x10) - polecenie | 0x00000100 (0x04) - wartoťŠ
    // = 0b00010100 (0x14)
    display_write_cmd(cfg, 0x10 | 0x04);

    // Ustawienie napiŕcia sygna│u steruj╣cego matryc╣ LCD / kontrastu
    // 0b10000000 (0x80) - polecenie | 0x01001000 (0x38) - wartoťŠ
    // = 0x11001000 (0xB8)
    display_write_cmd(cfg, 0x80 | 0x38);

    // Powrˇt do trybu polece˝ podstawowych
    // 0x00100001 (0x20) - polecenie
    display_write_cmd(cfg, 0x20);

    // Ustawienie trybu pracy wyťwietlacza - normalnego
    // 0x00001000 (0x08) - polecenie | 0b00000100 (0x04) - wartoťŠ
    // = 0b00001100 (0x0C)
    // Pozosta│e tryby pracy: ca│y wy│╣czony - 0b00000000 (0x00);
    // ca│y zapalony - 0x00000001 (0x01); odwrˇcony - 0x00000101 (0x05)
    display_write_cmd(cfg, 0x08 | 0x04);

    // Czyszczenie wyťwietlacza
    for (int i = 0; i < 504; i++)
        display_write_data(cfg, 0x00);
}

void display_set_dxy(struct display_config * cfg,
                     enum display_direction direction,
                     uint8_t column, uint8_t row)
{
    // Przejťcie w tryb polece˝ podstawowych i ustawienie kierunku rysowania
    if(direction == vertical)
        display_write_cmd(cfg, 0x20 | 0x02);
    else
        display_write_cmd(cfg, 0x20 | 0x00);

    display_write_cmd(cfg, 0x80 | column); // Wybˇr kolumny
    display_write_cmd(cfg, 0x40 | row); // Wybˇr wiersza
}

void display_write_cmd(struct display_config * cfg, uint8_t cmd) {
    // Wybˇr tryby transmisji polece˝
    HAL_GPIO_WritePin(cfg->dc_port, cfg->dc_pin, GPIO_PIN_RESET);

    // Odblokowanie wejťcia zegarowego
    HAL_GPIO_WritePin(cfg->ce_port, cfg->ce_pin, GPIO_PIN_RESET);
    // Transmisja danych interfejsem SPI
    HAL_SPI_Transmit(cfg->spi, &cmd, 1, 100);
    // Blokada wejťcia zegarowego
    HAL_GPIO_WritePin(cfg->ce_port, cfg->ce_pin, GPIO_PIN_SET);
}

void display_write_data(struct display_config * cfg, uint8_t data) {
    // Wybˇr tryby transmisji polece˝
    HAL_GPIO_WritePin(cfg->dc_port, cfg->dc_pin, GPIO_PIN_SET);

    // Odblokowanie wejťcia zegarowego
    HAL_GPIO_WritePin(cfg->ce_port, cfg->ce_pin, GPIO_PIN_RESET);
    // Transmisja danych interfejsem SPI
    HAL_SPI_Transmit(cfg->spi, &data, 1, 100);
    // Blokada wejťcia zegarowego
    HAL_GPIO_WritePin(cfg->ce_port, cfg->ce_pin, GPIO_PIN_SET);
}


void display_write_char(struct display_config * cfg, char chr)
{
    for (uint8_t i = 0; i < 5; i++)
        display_write_data(cfg, display_font[chr - 0x20][i]);
    display_write_data(cfg, 0x00);
}

void display_rewrite_buffer(struct display_config * cfg)
{
    display_set_dxy(cfg, horizontal, 0, 0);

    for(uint8_t i=0; i<5; i++)
        for(uint8_t j=0; j<14; j++)
            display_write_char(cfg, cfg->buffer[i][j]);
}

void display_clear_buffer(struct display_config * cfg)
{
    for(uint8_t i=0; i<6; i++)
        for(uint8_t j=0; j<14; j++)
            cfg->buffer[i][j] = ' ';
}

