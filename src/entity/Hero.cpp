#include <Hero.h>
#include <iostream>
#include <Renderer.h>
#include <Collision.h>
#include <Ennemy.h>
#include <set>



Hero::Hero(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name)
: Entity(map, textureSheet, position, name), m_direction(Vector2<int>(0,0)), m_pos_camera(Vector2<int>(500,500))
, MAXHEALTH(5), m_health(5)
{
	initPersonnge();
}

Hero::~Hero() {}

void Hero::update() {
	m_pos_camera=m_pos_camera+m_direction;
	//move all entities not of hero type in the opposite direction

	for (std::set<Entity*>::iterator it = Entity::m_entity.begin(); it != Entity::m_entity.end(); ++it)
	{
		std::string typeName = typeid(**it).name();
        typeName = typeName.substr(1, typeName.length() - 1);
		if(typeName == "Ennemy")
		{
			Ennemy* ennemy = dynamic_cast<Ennemy*>(*it);
			ennemy->setPosition(ennemy->getPosition()-m_direction);
		}
	}

	//load hearts
    for(int i=0;i<MAXHEALTH;i++){
		if(i<m_health){
			Renderer::getInstance()->drawCircle(Vector2<float>(15+i*34,15), 16, Renderer::Color(255,0,0));
		} else {
			Renderer::getInstance()->drawCircle(Vector2<float>(15+i*34,15), 16, Renderer::Color(50,50,50));
		}
    }
    //load full hearts

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