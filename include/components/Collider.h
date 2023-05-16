#ifndef _Collider_H
#define _Collider_H

#include <Vector2.h>
#include <vector>
#include <Entity.h>

class Collider { 
private:
    Vector2<int> m_size;

public:
    Collider(Vector2<int> size);
    
    std::vector<Entity*> allCollide(Vector2<int> position);
    bool isCollideWith(Entity &e);
    Vector2<int> getSize();


private:
    bool testIfCollide(Vector2<int> &position, Vector2<int> &colliderPosition, Vector2<int> &colliderSize);
    bool testIfPointCollide(Vector2<int> &position, Vector2<int> &point);
};

#endif