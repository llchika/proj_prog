#include <Ennemy.h>
#include <iostream>

Ennemy::Ennemy(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name)
: Entity(map, textureSheet, position, name), m_speed(1), MAXHEALTH(10), m_health(5), m_timer(0) {
	initPersonnge();
}

Ennemy::~Ennemy() {}

void Ennemy::update(Vector2<int> const& target) {
	


	//prit m_timer
	std::cout << m_timer << std::endl;

	//translate of on ex or y toward the target
	if (m_timer > 50) {
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

		m_timer = 0;
	}


	if (m_health <= 0) {
		//delete this; fait planter (probleme de mémoire)
		//setStatus(Status::DESTROY); //Status est privé dans ce contexte donc ca ne compile pas
	}
	GameObject::update();
	m_timer += 1;
}
