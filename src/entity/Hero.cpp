#include <Hero.h>
#include <constantes.h>

Hero::Hero(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name)
: Entity(map, textureSheet, position, name, Vector2<int>(JeuESIR::heroSize, JeuESIR::heroSize)), m_direction(Vector2<int>(0,0)) {
	initPersonnge();
}

Hero::~Hero() {}

void Hero::update() {
	setPosition(getPosition()+m_direction*m_speed);
	GameObject::update();
}

void Hero::modif_dir(sens direction) {
	switch (direction) {
		case sens::UP:
			if (Hero::GameObject::getPosition()[0]!=0) {
				Hero::GameObject::setPosition(Hero::GameObject::getPosition()+(Vector2<int>(-1,0)));
			}
			break;
		case sens::DOWN:
			if (Hero::GameObject::getPosition()[0]!=JeuESIR::maxScreenRow-1) {
				Hero::GameObject::setPosition(Hero::GameObject::getPosition()+(Vector2<int>(1,0)));
			}
			break;
		case sens::RIGHT:
			if (Hero::GameObject::getPosition()[1]!=JeuESIR::maxScreenCol-1) {
				Hero::GameObject::setPosition(Hero::GameObject::getPosition()+(Vector2<int>(0,1)));
			}
			break;
		case sens::LEFT:
			if (Hero::GameObject::getPosition()[1]!=0) {
				Hero::GameObject::setPosition(Hero::GameObject::getPosition()+(Vector2<int>(0,-1)));
			}
			break;
	}
}