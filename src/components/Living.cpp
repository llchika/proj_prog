#include <Living.h>
Living::Living(int maxHealth, Map* map, const Vector2<int>& positionHolder): 
MAXHEALTH(maxHealth), m_health(maxHealth), lifeBarMax(map, "ressources/tiles/fullbar.png", positionHolder+1, "lifeBarMax"),
lifeBarCurrent(map, "ressources/tiles/emptybar.png", positionHolder, "lifeBarCurrent")
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

void Living::update()
{
    lifeBarMax.update();
    lifeBarCurrent.update();
}
