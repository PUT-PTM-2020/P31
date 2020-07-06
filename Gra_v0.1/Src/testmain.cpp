#include "..\Inc\Level.hpp"
//wykomentowane, bo się z main.cpp kłóciło

int main(){
    //Generating test level
    Level l(true);

    l.Constructions.push_back(Construction(9, 32, 2));
	l.Constructions.push_back(Construction(34, 32, 2));
	l.Constructions.push_back(Construction(59, 32, 2));

 	std::vector<std::pair<uint8_t,uint8_t>> moveVec0;
    moveVec0.push_back(std::pair<uint8_t, uint8_t>(72, 0));
    moveVec0.push_back(std::pair<uint8_t, uint8_t>(72, 9));
    moveVec0.push_back(std::pair<uint8_t, uint8_t>(0, 9));
    moveVec0.push_back(std::pair<uint8_t, uint8_t>(0, 16));
    moveVec0.push_back(std::pair<uint8_t, uint8_t>(72, 16));
    moveVec0.push_back(std::pair<uint8_t, uint8_t>(72, 32));
    moveVec0.push_back(std::pair<uint8_t, uint8_t>(0, 32));
    moveVec0.push_back(std::pair<uint8_t, uint8_t>(0, 40));
    moveVec0.push_back(std::pair<uint8_t, uint8_t>(72, 40));

    l.Enemies.push_back(Enemy(0, 0, 1, true, moveVec0));
    l.Enemies.push_back(Enemy(12, 0, 1, true, moveVec0));
    l.Enemies.push_back(Enemy(24, 0, 1, true, moveVec0));
    l.Enemies.push_back(Enemy(36, 0, 1, true, moveVec0));
    l.Enemies.push_back(Enemy(48, 0, 1, true, moveVec0));
    l.Enemies.push_back(Enemy(60, 0, 1, true, moveVec0));
    l.Enemies.push_back(Enemy(72, 0, 1, true, moveVec0));

    l.saveF("D:\\Studia\\reposy\\test.txt");

    return 0;
}

