#ifndef _Mouse_H
#define _Mouse_H

#include <string>
#include <Entity.h>

/*
* Gestion de la souris du joueur (déplacement et attaque)
*/

class Mouse : public Entity {
public:
private:
public:
    /// Constructeur
    Mouse(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name);
    virtual ~Mouse();

    /**
    * \brief Met à jour la boule de feu
    */
    void update(Vector2<int> mousePose);
};

#endif