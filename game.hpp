#ifndef GAME_H
#define GAME_H

#include "map.hpp"
#include "snake.hpp"
#include <iostream>
#include <vector>

class Game
{
public:
    Game();
    Game(std::string mapPath);
    void start();
    void display();
    void initSnakes(std::string mapPath);
    void initFood();
    void handleEvent();
    void newFood(int id);
private:
    bool checkEmpty(Point p);
    Map map;
    int speed;
    bool ai;
    bool sound;
    std::vector<Snake> snakes;
    std::vector<Point> foods;
};

#endif // GAME_H
