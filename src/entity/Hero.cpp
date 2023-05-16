#include <Hero.h>

Hero::Hero(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name) :
	Entity(map, textureSheet, position, name), m_direction(Vector2<int>(0,0))
{
	initPersonnge();
}

Hero::~Hero() {}

void Hero::update()
{
	GameObject::update();
}

void Hero::modif_dir(sens direction) {
	switch (direction) {
		case sens::UP:
			setPosition(getPosition()+(Vector2<int>(-1,0)));
			break;
		case sens::DOWN:
			setPosition(getPosition()+(Vector2<int>(1,0)));
			break;
		case sens::RIGHT:
			setPosition(getPosition()+(Vector2<int>(0,1)));
			break;
		case sens::LEFT:
			setPosition(getPosition()+(Vector2<int>(0,-1)));
			break;
	}
}