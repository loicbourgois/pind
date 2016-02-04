#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>

class Game;

class Map
{
public:
    Map(Game * parent = nullptr);
    Map(Game * parent, std::string path);
    std::string toString();
private:
    std::vector< std::vector<char> > map;
    int width;
    int height;
    Game * parent;
};

#endif // MAP_H
