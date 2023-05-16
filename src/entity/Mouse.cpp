#include <Mouse.h>
#include <constantes.h>
#include <Collision.h>
Mouse::Mouse(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name)
: Entity(map, textureSheet, position, name) {
    initPersonnge();
}

Mouse::~Mouse() {}

void Mouse::update(Vector2<int> mousePos){
    setPosition(mousePos);

    



    GameObject::update();
}
