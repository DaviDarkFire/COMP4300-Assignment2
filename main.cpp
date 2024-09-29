#include "Entity.h"
#include "EntityManager.h"
#include "Game.h"
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
    // entityManager->printAllEntitiesFromMap();
    jogador->destroy();
    // entityManager->printAllEntitiesFromMap();
    entityManager->update();
    // entityManager->printAllEntitiesFromMap();
    entityManager->addEntity("jogadorBemTop");
    entityManager->update();
    // entityManager->printAllEntitiesFromMap();
    entityManager->addEntity("inimigo");
    auto inimigo = entityManager->addEntity("inimigo");
    auto inimigo1 = entityManager->addEntity("inimigo");
    auto bala1 = entityManager->addEntity("bala");
    auto bala2 = entityManager->addEntity("bala");
    auto bala3 = entityManager->addEntity("bala");
    entityManager->addEntity("bala");
    entityManager->addEntity("bala");
    entityManager->update();
    // entityManager->printAllEntitiesFromMap();
    bala1->destroy();
    bala2->destroy();
    bala3->destroy();
    inimigo->destroy();
    inimigo1->destroy();
    entityManager->update();
    entityManager->printAllEntitiesFromMap();
    std::cout << v1.dist(v2) << "\n";

    Game g("config.txt");
    g.run();
}