#include <Collider.h>
#include <Entity.h>

#include <Vector2.h>
#include <vector>

Collider::Collider(Vector2<int> size):m_size(size) {}


std::vector<Entity*> Collider::allCollide(Vector2<int> position)
{
    std::vector<Entity*> res = std::vector<Entity*>();
    for (std::set<Entity*>::iterator it = Entity::m_entity.begin(); it != Entity::m_entity.end(); ++it)
    {
        Vector2<int> pos = (*it)->getPosition();
        Vector2<int> size = (*it)->getSize();

        if (testIfCollide(position, pos, size))
            res.push_back((*it));
    }
    return res;
}

bool Collider::isCollideWith(Entity &e)
{
    Vector2<int> pos = e.getPosition();
    Vector2<int> size = e.getSize();

    if (testIfCollide(position, pos, size))
        return true
    return false;
}

Vector2<int> Collider::getSize()
{
    return m_size;
}


bool Collider::testIfCollide(Vector2<int> &position, Vector2<int> &colliderPosition, Vector2<int> &colliderSize)
{
    Vector2<int> x(colliderPosition[0]+colliderSize[0], colliderPosition[0]);// en haut à droite
    Vector2<int> y(colliderPosition[0], colliderPosition[0]+colliderSize[1]);// en bas à gauche
    Vector2<int> xy(colliderPosition[0]+colliderSize[0], colliderPosition[0]+colliderSize[1]);// en bas à droite

    if(testIfPointCollide(position , colliderPosition) 
        || testIfPointCollide(position , x) 
        || testIfPointCollide(position , y) 
        || testIfPointCollide(position , xy))
        return true;
    
    return false;
}

bool Collider::testIfPointCollide(Vector2<int> &position, Vector2<int> &point) {
    if (point[0] >= position[0]
        && point[0] <= position[0]+m_size[0]
        && point[1] >= position[1]
        && point[1] <= position[1]+m_size[1])
        return true;
    return false;
}