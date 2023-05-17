#ifndef _Ennemy_H
#define _EnnemyH

#include <string>
#include <Entity.h>

class Ennemy : public Entity {
public:

private:
    int m_speed;
    int const MAXHEALTH;
    int m_health;
    float m_timer;

public:

    Ennemy(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name);
    virtual ~Ennemy();

    void update(Vector2<int> const& target);
    
    void setHealth(int health) {
        m_health = health;
    }

    int getHealth() const {
        return m_health;
    }

    void setTimer(float timer) {
        m_timer = timer;
    }

    float getTimer() const {
        return m_timer;
    }
    

};

#endif