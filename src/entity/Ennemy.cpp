#include <Ennemy.h>
#include <iostream>

Ennemy::Ennemy(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name, bool target)
: Entity(map, textureSheet, position, name), m_speed(1), MAXHEALTH(10), m_health(5), m_timer(0), m_target(target) {
	initPersonnge();
}

Ennemy::~Ennemy() {}

void Ennemy::update(Vector2<int> const& target) {
	
	if (m_timer > 30) {

		if(m_target)
		{
			if (getPosition()[0] < target[0]) {
				setPosition(Vector2<int>(getPosition()[0] + m_speed, getPosition()[1]));
			}
			else if (getPosition()[0] > target[0]) {
				setPosition(Vector2<int>(getPosition()[0] - m_speed, getPosition()[1]));
			}
			if (getPosition()[1] < target[1]) {
				setPosition(Vector2<int>(getPosition()[0], getPosition()[1] + m_speed));
			}
			else if (getPosition()[1] > target[1]) {
				setPosition(Vector2<int>(getPosition()[0], getPosition()[1] - m_speed));
			}
		}
		else
		{
			//random deplace de 1 case
			int random = rand() % 4;
			switch (random) {
			case 0:
				setPosition(Vector2<int>(getPosition()[0] + m_speed, getPosition()[1]));
				break;
			case 1:
				setPosition(Vector2<int>(getPosition()[0] - m_speed, getPosition()[1]));
				break;
			case 2:	
				setPosition(Vector2<int>(getPosition()[0], getPosition()[1] + m_speed));
				break;
			case 3:
				setPosition(Vector2<int>(getPosition()[0], getPosition()[1] - m_speed));
				break;
			}
		}



		m_timer = 0;
	}


	if (m_health <= 0) {
		//delete this; fait planter (probleme de mémoire)
		//setStatus(Status::DESTROY); //Status est privé dans ce contexte donc ca ne compile pas
	}
	GameObject::update();
	m_timer += 1;
}
