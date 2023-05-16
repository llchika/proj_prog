#include <Hero.h>
#include <iostream>

Hero::Hero(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name)
: Entity(map, textureSheet, position, name), m_direction(Vector2<int>(0,0)), m_pos_camera(Vector2<int>(500,500)) {
	initPersonnge();
}

Hero::~Hero() {}

void Hero::update() {
	m_pos_camera=m_pos_camera+m_direction;
	GameObject::update();
}

void Hero::modif_dir(sens direction) {
	m_direction=Vector2<int>(0,0);
	switch (direction) {
		case sens::UP:
			if (Hero::GameObject::getPosition()[0]>0) {
				m_direction=m_direction+Vector2<int>(-1,0);
			}
			break;
		case sens::DOWN:
			if (Hero::GameObject::getPosition()[0]<1000) {
				m_direction=m_direction+Vector2<int>(1,0);
			}
			break;
		case sens::RIGHT:
			if (Hero::GameObject::getPosition()[1]<1000) {
				m_direction=m_direction+Vector2<int>(0,1);
			}
			break;
		case sens::LEFT:
			if (Hero::GameObject::getPosition()[1]>0) {
				m_direction=m_direction+Vector2<int>(0,-1);
			}
			break;
		default:
			break;
	}
}