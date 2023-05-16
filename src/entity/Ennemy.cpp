#include <Ennemy.h>
#include <iostream>

Ennemy::Ennemy(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name)
: Entity(map, textureSheet, position, name), m_speed(1) {
	initPersonnge();
}

Ennemy::~Ennemy() {}

void Ennemy::update(Vector2<int> const& target) {
	//move the target in a random direction
	int x = rand() % 3 - 1;
	int y = rand() % 3 - 1;
	//setPosition(getPosition() + Vector2<int>(x, y));
	
	GameObject::update();
}
