#include "Entity.h"

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

void Entity::setPosition() {
    cShape->circle.setPosition(cTransform->pos.x, cTransform->pos.y);
}

void Entity::setRotation(float angle) {
    cTransform->angle += angle;
    cShape->circle.setRotation(cTransform->angle);
}

sf::CircleShape Entity::getCShape() {
    return cShape->circle;
}

void Entity::move(){
    cTransform->velocity = {0,0};
    if (cInput->up)
    {
        cTransform->velocity.y = -7;
    }
    if (cInput->down)
    {
        cTransform->velocity.y = 7;
    }
    if (cInput->right)
    {
        cTransform->velocity.x = 7;
    }
    if (cInput->left)
    {
        cTransform->velocity.x = -7;
    }
    cTransform->pos.y += cTransform->velocity.y;
    cTransform->pos.x += cTransform->velocity.x;
}