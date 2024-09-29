#include "Game.h"
#include "Components.h"
#include "Vec2.h"

#include <SFML/Graphics/Color.hpp>
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
    while (m_running)
    {
        m_entityManager.update();
        if (!m_paused)
        {
            sEnemySpawner();
            sMovement();
            sCollision();
            sUserInput();
            sRender();
            
        } else 
        {
            sRender();
        }
        
        m_currentFrame++;
    }
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
    entity->cTransform = 
    std::make_shared<CTransform>(Vec2(initialPlayerPositionX, initialPlayerPositionY), Vec2(), 2.0f);
    entity->cShape = std::make_shared<CShape>(32.0f, 8, sf::Color(10,10,10), sf::Color(255, 0, 0), 4.0f);
    entity->cInput = std::make_shared<CInput>();
    m_player = entity;
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
}

