#ifndef _Collision_H
#define _Collision_H

#include <Vector2.h>
#include <vector>
#include <Entity.h>

static std::set<Entity*> m_entity;

class Collision {	
    public:
        static std::vector<Entity*> allCollide(Entity *e , Vector2<int> position) {
            std::vector<Entity*> res = std::vector<Entity*>();
            for (std::set<Entity*>::iterator it = Entity::m_entity.begin(); it != Entity::m_entity.end(); ++it)
            {
                Vector2<int> pos = (*it)->getPosition();
                Vector2<int> size = (*it)->getSize();

                if (testIfCollide(position, pos, size, e))
                    res.push_back(*it);
            }
            return res;
        }

    

    private:
        static bool testIfCollide(Vector2<int> &position, Vector2<int> &colliderPosition, Vector2<int> &colliderSize, Entity *e)
        {
            Vector2<int> x(colliderPosition[0]+colliderSize[0], colliderPosition[0]);// en haut à droite
            Vector2<int> y(colliderPosition[0], colliderPosition[0]+colliderSize[1]);// en bas à gauche
            Vector2<int> xy(colliderPosition[0]+colliderSize[0], colliderPosition[0]+colliderSize[1]);// en bas à droite

            if(testIfPointCollide(position , colliderPosition, e) 
                || testIfPointCollide(position , x, e) 
                || testIfPointCollide(position , y, e) 
                || testIfPointCollide(position , xy, e))
                return true;
            
            return false;
        }

        static bool testIfPointCollide(Vector2<int> &position, Vector2<int> &point, Entity *e) {
            if (point[0] >= position[0]
                && point[0] <= position[0]+e->getSize()[0]
                && point[1] >= position[1]
                && point[1] <= position[1]+e->getSize()[1])
                return true;
            return false;
        }
};
#endif