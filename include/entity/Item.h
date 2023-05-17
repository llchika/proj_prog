#ifndef _Item_H
#define _Item_H

#include <string>
#include <Entity.h>

class Item : public Entity {
public:
private:
public:

    Item(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name);
    virtual ~Item();

    /// <summary>
    /// Fonction permettant de mettre � jour les caract�ristiques du h�ro.
    /// </summary>
    void update();
};

#endif