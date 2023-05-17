#include <Obstacle.h>


Obstacle::Obstacle(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name)
: Entity(map, textureSheet, position, name){
    initPersonnge();
}

Obstacle::~Obstacle() {}

void Obstacle::update() {
    //GameObject::update();
}
