#include <Movements.h>


Movements::Movements(Vector2<int>& position, Collider& collider,float speed) : m_position(position), m_collider(collider), m_speed(speed), SCREEN_WIDTH(SCREEN_WIDTH), SCREEN_HEIGHT(SCREEN_HEIGHT)
{
}

Vector2<int> Movements::getPosition() const
{
    return m_position;
}
void Movements::setPosition(Vector2<int> position)
{
    m_position = position;
}

void Movements::move(Vector2<int> direction)
{
    Vector2<int> newPosition = m_position + direction * m_speed;
    /*
    std::vector<Entity*> collidedEntities = m_collider.collide(newPosition);
    if(!collidedEntities.empty())
    {
        m_position = newPosition;
    }
    else
    {

    }*/

}