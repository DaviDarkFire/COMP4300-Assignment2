#include "EntityManager.h"
#include "Entity.h"
#include <algorithm>
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
    std::cout << "\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< \n";
    for (auto entity: m_entities)
    {
        std::cout << entity->tag() << " " << entity->id() << " active: " << entity->isActive() << "\n";
    }
    std::cout << "m_entitiesToAdd size: " << m_entitiesToAdd.size() << "\n";
    std::cout << "m_totalEntities: " << m_totalEntities << "\n";
}

void EntityManager::printAllEntitiesFromMap()
{
    std::cout << "\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< \n";
    for (auto& [tag, entityVecFromMap] : m_entityMap)
    {
        std::cout << tag << "\n";
        for (auto entity: entityVecFromMap)
        {
            std::cout << "---> " << entity->id() << " active: " << entity->isActive() << "\n";
        }
    }
}

void EntityManager::update()
{
    for (auto e : m_entitiesToAdd)
    {
        m_entities.push_back(e);
        m_entityMap[e->tag()].push_back(e);
    }

    for (auto& [tag, entityVecFromMap] : m_entityMap)
    {
        removeDeadEntities(entityVecFromMap);
        removeDeadEntities(m_entities);
    }
    m_entitiesToAdd.clear();
}

void EntityManager::removeDeadEntities(EntityVec & vec)
{
    auto isNotActive = [](std::shared_ptr<Entity> entity) {return !entity->isActive();};
    vec.erase(std::remove_if(vec.begin(), vec.end(), isNotActive), vec.end());
}

const EntityVec & EntityManager::getEntities(const std::string & tag)
{
    return m_entityMap[tag];
}
