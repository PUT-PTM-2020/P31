#include "..\Inc\Level.hpp"
//wykomentowane, bo się z main.cpp kłóciło
/*
int main(){
    //Generating test level

    Level l(true);

    l.Constructions.push_back(Construction(20, 40, 2));
    l.Constructions.push_back(Construction(40, 40, 2));

    std::cout << l.Constructions.size() << std::endl;

    std::vector<std::pair<uint8_t,uint8_t>> moveVec;
    moveVec.push_back(std::pair<uint8_t, uint8_t>(40,20));
    moveVec.push_back(std::pair<uint8_t, uint8_t>(40,30));
    moveVec.push_back(std::pair<uint8_t, uint8_t>(30,30));
    moveVec.push_back(std::pair<uint8_t, uint8_t>(30,20));

    std::cout << moveVec.size() << std::endl;

    l.Enemies.push_back(Enemy(30, 20, 1, true, moveVec));

    std::cout << l.Enemies.size() << std::endl;

    l.player = Player(30,50,3);
    
    for (int i = 0; i < 10; i++){
        l.playerShoot();
        l.play();
    }

    return 0;
}
*/
