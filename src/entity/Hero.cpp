#include <Hero.h>
#include <constantes.h>

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
			if (getPosition()[0]!=0) {
				setPosition(getPosition()+(Vector2<int>(-1,0)));
			}
			break;
		case sens::DOWN:
			if (getPosition()[0]!=JeuESIR::maxScreenRow-1) {
				setPosition(getPosition()+(Vector2<int>(1,0)));
			}
			break;
		case sens::RIGHT:
			if (getPosition()[1]!=JeuESIR::maxScreenCol-1) {
				setPosition(getPosition()+(Vector2<int>(0,1)));
			}
			break;
		case sens::LEFT:
			if (getPosition()[1]!=0) {
				setPosition(getPosition()+(Vector2<int>(0,-1)));
			}
			break;
	}
}