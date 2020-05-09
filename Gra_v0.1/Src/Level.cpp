#include "..\Inc\Level.hpp"

Level::~Level(){}

bool Level::finished(){
    if ((Enemies.size() < 3) || (player.hp < 1)) {return true;}
    else { return false; }
}

void Level::playerShoot(){ 
    if (playerShot == nullptr){
        playerShot = &Shot(player.positionX+(player.getWidth()/2)+1, player.positionY+1, bulletSpeed);
    }
}

void Level::bulletManagement(bool sorce){
    Shot* shot;
    if (sorce){
        shot = playerShot;
    }
    else {
        shot = enemyShot;
    }
    
    if (shot != nullptr){
        std::pair<std::string, uint8_t> eShooted = shot->shooted(*this);
        if (eShooted.first != "null"){
            if (eShooted.first == "Enemies")
            {
                if (Enemies.at(eShooted.second).hit()){
                    Enemies.erase(Enemies.begin()+eShooted.second);
                }
            }
            else if (eShooted.first == "Constructions")
            {
                if (Constructions.at(eShooted.second).hit()){
                    Constructions.erase(Constructions.begin()+eShooted.second);
                }
            }
            else if (eShooted.first == "Player" && sorce)
            {
                player.hit();
            }
            
            if (sorce){
                playerShot = nullptr;
            }
            else {
                enemyShot = nullptr;
            }

        }
    }
}

void Level::playerCollision(){
    //TODO: Optimalisation based on distance form player
    for (uint8_t i = 0; i < Enemies.size(); i++){
        if (entityCollision(player, Enemies.at(i))){
            player.hit();
            Enemies.erase(Enemies.begin()+i);
        }
    }

    for (uint8_t i = 0; i < Constructions.size(); i++)
    {
        if (entityCollision(player, Constructions.at(i))){
            //TODO: player - construction collision handling
        }
    }
    
}

void Level::play(){
    
    //enemy bullet management
    bulletManagement(false);

    //player bullet management
    bulletManagement(false);

    //enemies movement
    for (uint8_t i = 0; i < Enemies.size(); i++){
        Enemies.at(i).movement();
        //TODO: player - enemy collision (check + handling)
    }
    
    
    //TODO: enemy shoot

}

void Level::save(std::string name){
    //TODO: void Level:save() [save level object to binary file]
    std::ofstream file;
    file.open(name, std::ios::binary);
    if (file){
        std::cout << "Dziala [TEST]\n";
        file.write(reinterpret_cast<const char*>(&bulletSpeed), sizeof(uint8_t));
        for(int i = 0; i < Enemies.size(); i++){
            file.write(reinterpret_cast<const char*>(&Enemies[i]), sizeof(Enemy));
        }
        for(int i = 0; i < Constructions.size(); i++){
            file.write(reinterpret_cast<const char*>(&Constructions[i]), sizeof(Construction));
        }
        std::cout << "Skonczyl [TEST]\n";
    } else {
        std::cout << "Nie dziala [TEST]\n";
    }
    file.close();
}

void Level::load(std::string name){
    //TODO: void Level::load() [loading level object from binary file]
    std::ifstream file(name, std::ios::binary);
}

void Level::enemyShoot(){
    //TODO: void Level::enemyShoot() [with sounds - require hpp for sound]
}

void Level::playerShoot(){
    //TODO: void Level::playerShoot() [with sounds - require hpp for sound]
}