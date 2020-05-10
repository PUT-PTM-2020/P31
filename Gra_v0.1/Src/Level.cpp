#include "..\Inc\Level.hpp"

Level::Level(bool eShooting): eShooting(eShooting), bulletSpeed(5){}

bool Level::finished(){
    if ((Enemies.size() < 3) || (player.hp < 1)) {return true;}
    else { return false; }
}

void Level::playerShoot(){ 
    if (playerShot.valid){
        playerShot = Shot(player.positionX+(player.getWidth()/2)+1, player.positionY+1, bulletSpeed, true);
    }
}

void Level::bulletManagement(bool sorce){
    Shot* shot;
    if (sorce){
        shot = &playerShot;
    }
    else {
        shot = &enemyShot;
    }
    
    shot->movement();

    if (shot->valid){
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
            
            shot->valid = false;
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

void Level::load(){
    //TODO: void Level::load() [loading level object from binary file]
}

void Level::enemyShoot(){
    //TODO: void Level::enemyShoot() [with sounds - require hpp for sound]
}