#include "..\Inc\Entity.hpp"

Entity::Entity(){}

Entity::~Entity(){}

bool Entity::hit(){
	hp -= 1;
	if (hp > 0){
		return false;
	}
	else {
		return true;
	}
}
