#include "Entity.h"
#include "EntityManager.h"
#include "Vec2.h"
#include <iostream>

int main() {
    Vec2 v1(1, 1);
    Vec2 v2(2, 2);

    std::string tag = "fodesabuceta";
    auto entiy = std::shared_ptr<Entity>(new Entity(2, tag));

    auto entityManager = new EntityManager();

    std::cout << v1.dist(v2) << "\n";
    std::cout << entiy->id() << "\n";
    std::cout << entiy->isActive() << "\n";
    std::cout << entiy->tag() << "\n";
}