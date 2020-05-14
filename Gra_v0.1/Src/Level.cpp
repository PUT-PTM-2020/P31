#include "..\Inc\Shot.hpp"
#include "..\Inc\Level.hpp"

Level::Level(bool eShooting): eShooting(eShooting), bulletSpeed(4), enemyShot(nullptr), playerShot(nullptr){}

bool Level::finished(){
    if ((Enemies.size() < 1) || (player.hp < 1)) {return true;}
    else { return false; }
}

void Level::playerShoot(){ 
    //TODO: playerShoot() add sound [requires hpp]
    if (playerShot != nullptr){
        playerShot = new Shot(player.positionX+(player.getWidth()/2)+1, player.positionY+1, bulletSpeed);
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
    

    if (shot!=nullptr){
        shot->movement();
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
            
            delete shot;
        }
        else if (shot->positionY > 100)
        {
            delete shot;
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
    bulletManagement(true);
    


    //enemies movement
    for (uint8_t i = 0; i < Enemies.size(); i++){
        Enemies.at(i).movement();
        //TODO: player - enemy collision (check + handling)
    }
    
    
    //TESTS ONLY - no general sense
    static uint8_t i = 0;
    if (i % 5 == 0)
    {
        enemyShoot();
        
    }
    i++;
    
    

    //TODO: enemy shoot

}

void Level::save(std::string name){
    std::ofstream file;
    int sizeE = Enemies.size();
    int sizeC = Constructions.size();
    file.open(name, std::ios::binary);
    if (file){
        file.write(reinterpret_cast<char*>(&sizeE), sizeof(int));
        file.write(reinterpret_cast<char*>(&sizeC), sizeof(int));
        for(int i = 0; i < Enemies.size(); i++){
            file.write(reinterpret_cast<char*>(&Enemies[i].positionX), sizeof(uint8_t));
            file.write(reinterpret_cast<char*>(&Enemies[i].positionY), sizeof(uint8_t));
            file.write(reinterpret_cast<char*>(&Enemies[i].hp), sizeof(uint8_t));
        }
        for(int i = 0; i < Constructions.size(); i++){
            file.write(reinterpret_cast<char*>(&Constructions[i].positionX), sizeof(uint8_t));
            file.write(reinterpret_cast<char*>(&Constructions[i].positionY), sizeof(uint8_t));
            file.write(reinterpret_cast<char*>(&Constructions[i].hp), sizeof(uint8_t));
        }
    }
    file.close();
}

void Level::load(std::string name){
    std::ifstream file;
    int sizeE = 0, sizeC = 0;
    file.open(name, std::ios::binary);
    if (file){
        file.read(reinterpret_cast<char*>(&sizeE), sizeof(sizeE));
        file.read(reinterpret_cast<char*>(&sizeC), sizeof(sizeC));
        Enemy etmp;
        for(int i = 0; i < sizeE; i++){
            file.read(reinterpret_cast<char*>(&etmp.positionX), sizeof(uint8_t));
            file.read(reinterpret_cast<char*>(&etmp.positionY), sizeof(uint8_t));
            file.read(reinterpret_cast<char*>(&etmp.hp), sizeof(uint8_t));
            Enemies.push_back(etmp);
        }
        Construction ctmp;
        for(int i = 0; i < sizeC; i++){
            file.read(reinterpret_cast<char*>(&ctmp.positionX), sizeof(uint8_t));
            file.read(reinterpret_cast<char*>(&ctmp.positionY), sizeof(uint8_t));
            file.read(reinterpret_cast<char*>(&ctmp.hp), sizeof(uint8_t));
            Constructions.push_back(ctmp);
        }
    }
    file.close();
}

void Level::enemyShoot(){
    //TODO: void Level::enemyShoot() [with sounds - require hpp for sound]

    //TESTS ONLY - no general sense
    if (enemyShot == nullptr)
    {
        if (Enemies.size() > 0)
        {
            enemyShot = new Shot(Enemies[0].positionX+(Enemies[0].getWidth()/2)+1, Enemies[0].positionY+Enemies[0].getHeight(), -bulletSpeed);
        }
        
    }
    
    
}