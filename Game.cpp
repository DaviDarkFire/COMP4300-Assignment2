#include "Game.h"

#include <iostream>
#include <fstream>
#include <sstream>

Game::Game(const std::string & config)
{
    init(config);
}

void Game::init(const std::string & path)
{
    std::ifstream fin(path);
    std::string fontFile, line;
    int w, h, fl, fs, fontSize, fontR, fontG, fontB;
    while (std::getline(fin, line))
    {  
        std::istringstream iss(line);
        std::string identifier;
        iss >> identifier; 

       if (identifier == "Window") 
       { 
            iss >> w >> h >> fl >> fs;
       } else if (identifier == "Font")
       {
            fin >> fontFile >> fontSize >> fontR >> fontG >> fontB;
       } else if (identifier == "Player")
       {
            iss >> m_playerConfig.SR >> m_playerConfig.CR >> m_playerConfig.S >> m_playerConfig.FR >>
            m_playerConfig.FG >> m_playerConfig.FB >> m_playerConfig.OR >> m_playerConfig.OG >> m_playerConfig.OB >>
            m_playerConfig.OT >> m_playerConfig.V;
       } else if (identifier == "Enemy")
       {
            iss >> m_enemyConfig.SR >> m_enemyConfig.CR >> m_enemyConfig.SMIN >> m_enemyConfig.SMAX >>
            m_enemyConfig.OR >> m_enemyConfig.OG >> m_enemyConfig.OB >> m_enemyConfig.OT >> m_enemyConfig.VMIN >>
            m_enemyConfig.VMAX >> m_enemyConfig.L >> m_enemyConfig.SI;
       } else if (identifier == "Bullet")
       {
            iss >> m_bulletConfig.SR >> m_bulletConfig.CR >> m_bulletConfig.S >> m_bulletConfig.FR >> m_bulletConfig.FG >>
            m_bulletConfig.FB >> m_bulletConfig.OR >> m_bulletConfig.OG >> m_bulletConfig.OB >> m_bulletConfig.OT >> m_bulletConfig.V >>
            m_bulletConfig.L;
       }
       std::cout << "oe";
    }
}