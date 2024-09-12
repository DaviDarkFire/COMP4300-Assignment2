#include "Entity.h"
#include "EntityManager.h"
#include "Vec2.h"
#include <iostream>

int main() {
    Vec2 v1(1, 1);
    Vec2 v2(2, 2);

    std::string tag = "fodesabuceta";

    auto entityManager = new EntityManager();
    entityManager->addEntity("jogador");
    // entityManager->update();
    entityManager->printAllEntities();

    // std::cout << v1.dist(v2) << "\n";
}