#ifndef _Item_H
#define _Item_H

#include <string>
#include <Entity.h>

/*
* Classe qui gère les differents objets
*/

class Item : public Entity {
public:
private:
public:

    Item(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name);
    virtual ~Item();

    /**
    * \brief Fonction qui met à jour la position de l'objet et son affichage
    */
    void update();
};

#endif