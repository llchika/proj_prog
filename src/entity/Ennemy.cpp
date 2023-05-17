#include <Ennemy.h>
#include <iostream>

Ennemy::Ennemy(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name)
: Entity(map, textureSheet, position, name), m_speed(1), MAXHEALTH(10), m_health(5){
	initPersonnge();
}

Ennemy::~Ennemy() {}

void Ennemy::update(Vector2<int> const& target) {
	//move the target in a random direction
	//int x = rand() % 3 - 1;
	//int y = rand() % 3 - 1;
	//setPosition(getPosition() + Vector2<int>(x, y));

	if (m_health <= 0) {
		//delete this; fait planter (probleme de mémoire)
		setStatus(Status::DESTROY); //Status est privé dans ce contexte donc ca ne compile pas
	}
	GameObject::update();
}
