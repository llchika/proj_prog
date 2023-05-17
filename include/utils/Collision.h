#ifndef _Collision_H
#define _Collision_H

#include <Vector2.h>
#include <vector>
#include <Entity.h>

static std::set<Entity*> m_entity;

class Collision {	
    public:
        /// <summary>
        /// Test si une Entity est en collision avec d'autres Entity
        /// </summary>
        /// <param name="e">Entity à tester</param>
        /// <param name="position">Position de l'Entity à tester</param>
        /// <returns> Retourne la listes de tout les Entity qui sont en collision avec l'Entity e </returns>
        static std::vector<Entity*> allCollide(Entity *e , Vector2<int> position) 
        {
            std::vector<Entity*> res = std::vector<Entity*>();
            for (std::set<Entity*>::iterator it = Entity::m_entity.begin(); it != Entity::m_entity.end(); ++it)
            {
                if (testIfCollide(e, *it, position))
                    if (*it != e)
                        res.push_back(*it);
            }
            return res;
        }
        /// <summary>
        /// Test si deux Entity sont en collision
        /// </summary>
        /// <param name="e1">Entity 1</param>
        /// <param name="e2">Entity 2</param>
        /// <returns> Retourne vrai si les deux Entity sont en collision, faux sinon </returns>
        static bool isCollideWith(Entity *e1, Entity *e2)
        {
            Vector2<int> pos = e1->getPosition();
            if (testIfCollide(e1, e2, pos))
                if (e1 != e2)
                    return true;
            
            return false;
        }

    private:
        /// <summary>
        /// Test si les 4 points de l'Entity sont en collision
        /// </summary>
        /// <param name="e1">Entity 1</param>
        /// <param name="e2">Entity 2</param>
        /// <param name="position">Position de l'Entity à tester</param>
        /// <returns> retourne vrai si au moins 1 point d'Entity 2 est en collision avec Entity 1 </returns>
        static bool testIfCollide(Entity *e1, Entity *e2, Vector2<int>& position)
        {
            Vector2<int> e2Pos = e2->getPosition();
            Vector2<int> e2Size = e2->getSize();
            Vector2<int> x(e2Pos[0]+e2Size[0], e2Pos[0]);// en haut à droite
            Vector2<int> y(e2Pos[0], e2Pos[0]+e2Size[1]);// en bas à gauche
            Vector2<int> xy(e2Pos[0]+e2Size[0], e2Pos[0]+e2Size[1]);// en bas à droite

            if(testIfPointCollide(e1 , e2Pos, position) 
                || testIfPointCollide(e1 , x, position) 
                || testIfPointCollide(e1 , y, position) 
                || testIfPointCollide(e1 , xy, position))
                return true;
            
            return false;
        }

        static bool testIfPointCollide(Entity *e1, Vector2<int> &point, Vector2<int>& position) {
            if (point[0] >= position[0]
                && point[0] <= position[0]+e1->getSize()[0]
                && point[1] >= position[1]
                && point[1] <= position[1]+e1->getSize()[1])
                return true;
            return false;
        }
};
#endif