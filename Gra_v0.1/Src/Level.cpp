#include "..\Inc\Shot.hpp"
#include "..\Inc\Level.hpp"

Level::Level(bool eShooting): eShooting(eShooting), bulletSpeed(1), enemyShot(nullptr), playerShot(nullptr), boss_ptr(nullptr){}

bool Level::finished(){
    if ((Enemies.size() < 1 && boss_ptr == nullptr) || (player.hp < 1)) {return true;}
    else { return false; }
}

bool Level::playerShoot(){
    //TODO: Level::playerShoot() add sound [requires hpp]
    if (playerShot == nullptr){
        playerShot = new Shot(player.positionX+(player.getWidth()/2)+1, player.positionY-1, bulletSpeed);
        return true;
    }
    else return false;
    
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
    	bool bbb = false;
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
            
            if (sorce){
            	delete playerShot;
            	                playerShot = nullptr;
            }
            else {
            	delete enemyShot;
            	                enemyShot = nullptr;
            }
            bool aaa = (shot==nullptr);
        }
        else if (shot->positionY > 47)
        {
            if (sorce){
                delete playerShot;
                playerShot = nullptr;
            }
            else {
                delete enemyShot;
                enemyShot = nullptr;
            }
            bbb = (shot==nullptr);

        }
        
    }
}

void Level::playerCollision(){
    for (uint8_t i = 0; i < Enemies.size(); i++){
        if (entityCollision(player, Enemies.at(i))){
            player.hit();
            Enemies.erase(Enemies.begin()+i);
        }
    }    
}

void Level::play(){
    
    //player bullet management
    bulletManagement(true);
    
    //enemies movement
    for (uint8_t i = 0; i < Enemies.size(); i++){
        Enemies.at(i).movement();
    }
    
    playerCollision();

    if (boss_ptr == nullptr){
        //enemy bullet management
        enemyShoot();
        bulletManagement(false);
    }
    else {
        if (Enemies.size() < 4){
            bossShoot();
        }
    }
    
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
    //TODO: Level::enemyShoot() add sound [require hpp]

    if (enemyShot == nullptr) {
        if (Enemies.size() > 0) {
            for (uint8_t i=0; i < Enemies.size(); i++){
                if (lineCollision(Enemies[i].positionX, Enemies[i].positionX+Enemies[i].getWidth()-1, player.positionX) || lineCollision(Enemies[i].positionX, Enemies[i].positionX+Enemies[i].getWidth()-1, player.positionX+player.getWidth()-1)){
                    static uint8_t i = 0;
                    if (i == 5) {
                        enemyShot = new Shot(Enemies[i].positionX+(Enemies[i].getWidth()/2)+1, Enemies[i].positionY+Enemies[i].getHeight(), -bulletSpeed);
                        //sound
                        i=0;
                    }
                    else {
                        i++;
                    }
                    
                }
            }
        }
    }
}

void Level::bossShoot(){
    std::pair<uint8_t, uint8_t> q1(player.positionX+(player.getWidth()/2)-(Enemy::width/2), 50);
    std::vector<std::pair<uint8_t, uint8_t>> qqq;
    qqq.push_back(q1);
    Enemy tmp = Enemy(player.positionX+(player.getWidth()/2)-(Enemy::width/2), boss_ptr->positionY + boss_ptr->getHeight(), 1, false, qqq);
    tmp.speed = bulletSpeed;
    Enemies.push_back(tmp);
}