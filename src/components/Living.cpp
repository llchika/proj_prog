#include "../../include/components/Living.h"

Living::Living(int maxHealth) : MAXHEALTH(maxHealth), m_health(maxHealth)
{
}

int Living::getHealth() const
{
    return m_health;
}

void Living::setHealth(int health)
{
    m_health = health;
}