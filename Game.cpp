#include "Game.h"
#include "Components.h"
#include "Vec2.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>
#include <fstream>
#include <memory>

Game::Game(const std::string & config)
{
    init(config);
}

void Game::init(const std::string & path)
{
    readFromFile(path);
    setWindow();
    setFont();
}

void Game::run()
{
    //TODO: add pause functionality
    //some systems should work while pause some systems shouldn't
    spawnPlayer();
    while (m_running)
    {
        m_entityManager.update();
        if (!m_paused)
        {            
            // sEnemySpawner();
            sMovement();
            // sCollision();
            sUserInput();
            sRender();
            
        } else 
        {
            sRender();
        }
        
        m_currentFrame++;
    }
}

void Game::sUserInput()
{
    sf::Event event;
    while (m_window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed) 
        {
            m_running = false;
            m_window.close();
        }

        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::W:                
                    m_player->cInput->up = true;
                    break;
                case sf::Keyboard::S:
                    m_player->cInput->down = true;
                    break;
                case sf::Keyboard::A:
                    m_player->cInput->left = true;
                    break;
                case sf::Keyboard::D:
                    m_player->cInput->right = true;
                    break;
                default:
                    break;
            }
        }
        if (event.type == sf::Event::KeyReleased)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::W:
                    m_player->cInput->up = false;
                    break;
                case sf::Keyboard::S:
                    m_player->cInput->down = false;
                    break;
                case sf::Keyboard::A:
                    m_player->cInput->left = false;
                    break;
                case sf::Keyboard::D:
                    m_player->cInput->right = false;
                    break;
                default:
                    break;
            }
        }
    }
}

void Game::sRender()
{
    m_window.clear();
    for (auto e : m_entityManager.getEntities())
    {
        e->setPosition();
        e->setRotation(e->getShapePointCount());
        m_window.draw(e->getCShape());
    }
    m_window.display();
}

void Game::setPaused(bool paused)
{
    m_paused = paused;
}

void Game::spawnPlayer()
{
    auto entity = m_entityManager.addEntity("player");
    float initialPlayerPositionX = m_window.getSize().x / 2.0f;
    float initialPlayerPositionY = m_window.getSize().y / 2.0f;
    /*TODO: need to calculate x and y components of player speed based on m_playerConfig.S
    need to add the CCollision component*/
    entity->cTransform = std::make_shared<CTransform>(
        Vec2(initialPlayerPositionX, initialPlayerPositionY), 
        calculateXAndYCoordinatesForSpeed(m_playerConfig.S),
        calculateAngleForSpeed(m_playerConfig.S));
    entity->cShape = std::make_shared<CShape>(
        m_playerConfig.SR, 
        m_playerConfig.V, 
        sf::Color(m_playerConfig.FR,m_playerConfig.FG,m_playerConfig.FB), 
        sf::Color(m_playerConfig.OR, m_playerConfig.OG, m_playerConfig.OB), 
        m_playerConfig.OT);
    entity->cInput = std::make_shared<CInput>();
    m_player = entity;
}

void Game::spawnEnemy()
{
    auto entity = m_entityManager.addEntity("enemy");

    //TODO: needing to populate data with enemy configuration
    int amountOfVertices = rng(m_enemyConfig.VMIN, m_enemyConfig.VMAX);
    entity->cShape = std::make_shared<CShape>(
        m_enemyConfig.SR, 
        amountOfVertices, 
        sf::Color(rng(1, 255),rng(1, 255), rng(1, 255)), 
        sf::Color(m_enemyConfig.OR, m_enemyConfig.OG, m_enemyConfig.OB), 
        m_enemyConfig.OT);


    /* added a little difference from the specification: the higher the amount of vertices, 
    higher the speed of the enemy */
    entity->cTransform = std::make_shared<CTransform>( 
        generateValidStartingPosition(m_enemyConfig.CR), 
        calculateXAndYCoordinatesForSpeed(amountOfVertices),
        calculateAngleForSpeed(amountOfVertices));

    //TODO: need to create the CCollision, CScore and CLifespan components

}

Vec2 Game::generateValidStartingPosition(int collisionRadius)
{
    //TODO: need also to check if the starting position is not colliding with player position
    return Vec2(rng(collisionRadius, m_window.getSize().x - collisionRadius), 
                rng(collisionRadius, m_window.getSize().y - collisionRadius));
}

Vec2 Game::calculateXAndYCoordinatesForSpeed(int speed)
{
    //TODO: implement this
}

Vec2 Game::calculateAngleForSpeed(int speed)
{
    //TODO: implement this
}

int Game::rng(int min, int max)
{
    return rand()%(max-min + 1) + min;
}

void Game::readFromFile(const std::string & path)
{
    std::ifstream fin(path);
    std::string line, identifier;
     if (fin.is_open()) {
          while (fin.good()) {
               fin >> line;
               std::cout << line;               
     
                  if (line == "Window") {
                      fin >> m_w >> m_h >> m_fl >> m_fs;                              
                  }
                  else if (line == "Font") {
                      fin >> m_fontFile >> m_fontSize >> m_fontR >> m_fontG >> m_fontB;          
                  }
                  else if (line == "Player") {
                      fin >> m_playerConfig.SR >> m_playerConfig.CR >> m_playerConfig.S >> m_playerConfig.FR 
                          >> m_playerConfig.FG >> m_playerConfig.FB >> m_playerConfig.OR >> m_playerConfig.OG 
                          >> m_playerConfig.OB >> m_playerConfig.OT >> m_playerConfig.V;
                  }
                  else if (line == "Enemy") {
                      fin >> m_enemyConfig.SR >> m_enemyConfig.CR >> m_enemyConfig.SMIN >> m_enemyConfig.SMAX 
                          >> m_enemyConfig.OR >> m_enemyConfig.OG >> m_enemyConfig.OB >> m_enemyConfig.OT 
                          >> m_enemyConfig.VMIN >> m_enemyConfig.VMAX >> m_enemyConfig.L >> m_enemyConfig.SI;
                  }
                  else if (line == "Bullet") {
                      fin >> m_bulletConfig.SR >> m_bulletConfig.CR >> m_bulletConfig.S >> m_bulletConfig.FR 
                          >> m_bulletConfig.FG >> m_bulletConfig.FB >> m_bulletConfig.OR >> m_bulletConfig.OG 
                          >> m_bulletConfig.OB >> m_bulletConfig.OT >> m_bulletConfig.V >> m_bulletConfig.L;
                  }
          }
     }
    fin.close();
}

void Game::setWindow()
{
    if (m_fs == 1)
    {
        sf::VideoMode desktop = sf::VideoMode::getDesktopMode();    
        m_window.create(desktop, "Joguin", sf::Style::Fullscreen);
    } else 
    {
        m_window.create(sf::VideoMode(m_w, m_h), "Joguin");
    }
    m_window.setFramerateLimit(m_fl);    
}

void Game::setFont()
{
    m_font.loadFromFile(m_fontFile);    
    if (!m_font.loadFromFile(m_fontFile))
    {
        return;
    }
}

void Game::sMovement()
{
    m_player->move();
}

