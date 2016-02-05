#include "snake.hpp"
#include "map.hpp"

unsigned int Snake::count = 0;

Snake::Snake(bool isIa) :
    isIa(isIa)
{
    id = count;
    count++;
    speed.x = 1;
    speed.y = 0;
}

void Snake::addBodyPart(int x, int y)
{
    body.push_back(Point(x,y));
}

void Snake::move(Map * map, Point food, std::vector<Snake> snakes)
{
    for(int i = body.size() - 1 ; i > 0 ; i--)
    {
        body[i].x = body[i-1].x;
        body[i].y = body[i-1].y;
    }
    body[0].x += speed.x;
    body[0].y += speed.y;
    body[0].x %= map->getWidth();
    body[0].y %= map->getHeight();
}

std::vector<Point> Snake::getBody()
{
    return body;
}
