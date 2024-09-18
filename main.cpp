#include "Entity.h"
#include "EntityManager.h"
#include "Vec2.h"
#include <iostream>

int main() {
    Vec2 v1(1, 1);
    Vec2 v2(2, 2);

    std::string tag = "fodesabuceta";

    auto entityManager = new EntityManager();
    auto jogador = entityManager->addEntity("jogador");
    entityManager->addEntity("inimigo");
    entityManager->addEntity("inimigo");
    entityManager->addEntity("inimigo");
    entityManager->addEntity("inimigo");
    entityManager->addEntity("inimigo");
    entityManager->addEntity("bala");
    entityManager->addEntity("bala");
    entityManager->addEntity("bala");
    entityManager->update();
    entityManager->printAllEntities();
    jogador->destroy();
    entityManager->printAllEntities();
    entityManager->update();
    entityManager->printAllEntities();
    entityManager->addEntity("jogadorBemTop");
    entityManager->printAllEntities();
    entityManager->update();
    entityManager->printAllEntities();


    // std::cout << v1.dist(v2) << "\n";
}