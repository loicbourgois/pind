#ifndef GAME_H
#define GAME_H

#include "map.hpp"
#include <iostream>

class Game
{
public:
    Game();
    Game(std::string mapPath);
    void start();
    void display();
private:
    Map map;
};

#endif // GAME_H
