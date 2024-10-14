#pragma once

#include "Entity.h"
#include "EntityManager.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

struct PlayerConfig {
    int SR, CR, FR, FG, FB, OR, OG, OB, OT, V;
    float S;
};
struct EnemyConfig {
    int SR, CR, OR, OG, OB, OT, VMIN, VMAX, L, SI;
    float SMIN, SMAX;
};
struct BulletConfig {
    int SR, CR, FR, FG, FB, OR, OG, OB, OT, V, L;
    float S;
};

class Game {
    sf::RenderWindow m_window;
    EntityManager m_entityManager;
    sf::Font m_font;
    sf::Text m_text;
    PlayerConfig m_playerConfig;
    EnemyConfig m_enemyConfig;
    BulletConfig m_bulletConfig;
    int m_score = 0;
    int m_currentFrame = 0;
    int m_lastEnemySpawnTime = 0;
    bool m_paused = false;
    bool m_running = true;
    std::string m_fontFile;
    int m_w, m_h, m_fl, m_fs, m_fontSize, m_fontR, m_fontG, m_fontB;

    std::shared_ptr<Entity> m_player;

    void init(const std::string & config);
    void readFromFile(const std::string & config);
    void setWindow();
    void setFont();
    void setPaused(bool paused);

    void sMovement();
    void sUserInput();
    void sLifespan();
    void sRender();
    void sEnemySpawner();
    void sCollision();

    void spawnPlayer();
    void spawnEnemy();
    void spawnSmallEnemies(std::shared_ptr<Entity> entity);
    void spawnBullet(std::shared_ptr<Entity> entity, const Vec2 & mousePos);
    void spawnSpecialWeapon(std::shared_ptr<Entity> entity);

    Vec2 generateValidStartingPosition(int collisionRadius);
    int rng(int min, int max);
    Vec2 calculateRandomComponentsForSpeed(int speed);

public:
    Game(const std::string & config);

    void run();
};