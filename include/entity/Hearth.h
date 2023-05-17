#ifndef _Heart_H
#define _Hearth_H

#include <string>
#include <Item.h>

class Hearth : public Item {
public:
private:
public:

    Hearth(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name);
    virtual ~Hearth();
};

#endif