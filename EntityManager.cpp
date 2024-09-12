#include "EntityManager.h"
#include "Entity.h"
#include <memory>
#include <iostream>


EntityManager::EntityManager(){}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string & tag)
{
    auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));
    m_entitiesToAdd.push_back(entity);
    return entity;
}

void EntityManager::printAllEntities()
{
    for (auto entity: m_entities)
    {
        std::cout << entity->tag() << " " << entity->id() << " esta ativo: " << entity->isActive() << "\n";
    }
}

void EntityManager::update()
{
    for (auto e : m_entitiesToAdd)
    {
        m_entities.push_back(e);
        // m_entityMap[e->tag()] = m_entitiesToAdd;
    }

    for (auto& [tag, entityVec] : m_entityMap)
    {
        removeDeadEntities(entityVec);
    }
}

void EntityManager::removeDeadEntities(EntityVec & vec)
{

}
