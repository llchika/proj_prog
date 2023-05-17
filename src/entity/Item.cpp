#include <Item.h>


Item::Item(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name)
: Entity(map, textureSheet, position, name){
    initPersonnge();
}

Item::~Item() {}

void Item::update(){
    //GameObject::update();
}
