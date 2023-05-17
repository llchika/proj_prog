#include <Hearth.h>


Hearth::Hearth(Map* map, const char* textureSheet, const Vector2<int>& position, std::string name)
: Item(map, textureSheet, position, name) {}

Hearth::~Hearth() {}
