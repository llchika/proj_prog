#include <Mouse.h>



Mouse::Mouse(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name)
: Entity(map, textureSheet, position, name) {
    initPersonnge();
}

Mouse::~Mouse() {}

void Mouse::update() {
    setPosition(getPosition());
    GameObject::update();
}
