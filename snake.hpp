#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "point.hpp"
#include <string>

class Map;
class Game;

class Snake
{
public:
    Snake(Game * game, bool isBot = false);
    void addBodyPart(int x, int y);
    void addHead(int x, int y);
    void move(Map * map, std::vector<Point> foods, std::vector<Snake> snakes);
    std::vector<Point> getBody();
    void setDirection(int d);
private:
    void think(Map *map, std::vector<Snake> snakes, std::vector<Point> foods);
    Game * game;
    static unsigned int count;
    std::vector<Point> body;
    Point speed;
    bool isBot;
    bool isAlive;
    int id;
    int direction;
};

#endif // SNAKE_H
