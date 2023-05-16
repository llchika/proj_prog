#include <Hero.h>

Hero::Hero(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name) :
	Entity(map, textureSheet, position, name)
{
	initPersonnge();
}

Hero::~Hero()
{
}

void Hero::update()
{
	GameObject::update();
}

