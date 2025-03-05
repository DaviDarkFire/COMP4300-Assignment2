#include "Entity.h"
#include "Vec2.h"

Entity::Entity(const size_t id, const std::string & tag): m_id(id), m_tag(tag){}

bool Entity::isActive() const {
    return m_active;
}

const std::string & Entity::tag() const
{
    return m_tag;
}

const size_t Entity::id() const
{
    return m_id;
}

void Entity::destroy() 
{
    m_active = false;
}

void Entity::setPosition() 
{
    cShape->circle.setPosition(cTransform->pos.x, cTransform->pos.y);
}

Vec2 Entity::getPosition() 
{
    return cTransform->pos;
}

int Entity::getColisionRadius()
{
    return cCollision->radius;
}

void Entity::setRotation(float angle) {
    cTransform->angle += angle;
    cShape->circle.setRotation(cTransform->angle);
}

sf::CircleShape Entity::getCShape() {
    return cShape->circle;
}

int Entity::getShapePointCount() 
{
    return cShape->circle.getPointCount();
}