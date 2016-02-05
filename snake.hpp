#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "point.hpp"

class Map;

class Snake
{
public:
    Snake(bool isIa = false);
    void addBodyPart(int x, int y);
    void addHead(int x, int y);
    void move(Map * map, Point food, std::vector<Snake> snakes);
    std::vector<Point> getBody();
private:
    static unsigned int count;
    std::vector<Point> body;
    Point speed;
    bool isIa;
    int id;
};

#endif // SNAKE_H
