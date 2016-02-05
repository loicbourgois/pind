#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <snake.hpp>

class Game;

class Map
{
public:
    Map(Game * parent = nullptr);
    Map(Game * parent, std::string path);
    std::string toString();
    std::string toString(std::vector<Snake> snakes);
    std::string toString(std::vector<Snake> snakes, Point food);
    int getWidth() {return width;}
    int getHeight() {return height;}
    bool caseIsEmpty(int x, int y);
private:
    std::vector< std::vector<char> > map;
    int width;
    int height;
    Game * parent;
};

#endif // MAP_H
