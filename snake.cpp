#include "snake.hpp"
#include "map.hpp"
#include "game.hpp"

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

unsigned int Snake::count = 0;

Snake::Snake(Game *game, bool isBot) :
    game(game),
    isBot(isBot),
    isAlive(true)
{
    id = count;
    count++;
    speed.x = 0;
    speed.y = 0;
    direction = NULL;
    setDirection(RIGHT);
}

void Snake::addBodyPart(int x, int y)
{
    body.push_back(Point(x,y));
}

void Snake::move(Map * map, std::vector<Point> foods, std::vector<Snake> snakes)
{
    if(!isAlive)
        return;
    if(isBot)
    {
        think(map, snakes, foods);
    }
    // Move
    for(int i = body.size() - 1 ; i > 0 ; i--)
    {
        body[i].x = body[i-1].x;
        body[i].y = body[i-1].y;
    }
    body[0].x += speed.x +  map->getWidth();
    body[0].y += speed.y + map->getHeight();
    body[0].x %= map->getWidth();
    body[0].y %= map->getHeight();

    for(int i = 0 ; i < foods.size() ; i++)
    {
        if(foods[i].x == body[0].x && foods[i].y == body[0].y)
        {
            this->game->newFood(i);
            addBodyPart(body[0].x, body[0].y);
        }
    }
    // Walls
    if(!map->caseIsEmpty(body[0].x, body[0].y))
    {
        this->isAlive = false;
    }
    // Snakes
    for(int i = 0 ; i < snakes.size() ; i++)
    {

        int firstJ = 0;
        if(i != this->id)
            firstJ = 1;

        for(int j = firstJ ; j < snakes[i].body.size() ; j++)
        {
            if(snakes[i].body[j].x == body[0].x && snakes[i].body[j].y == body[0].y)
            {
                this->isAlive = false;
            }
        }
    }
}

std::vector<Point> Snake::getBody()
{
    return body;
}

void Snake::setDirection(int d)
{
    switch (d) {
    case UP:
        if(direction == LEFT || direction == RIGHT || direction == NULL)
        {
            speed.x = 0;
            speed.y = -1;
            direction = d;
        }
        break;
    case DOWN:
        if(direction == LEFT || direction == RIGHT || direction == NULL)
        {
            speed.x = 0;
            speed.y = 1;
            direction = d;
        }
        break;
    case LEFT:if(direction == UP || direction == DOWN || direction == NULL)
        {
            speed.x = -1;
            speed.y = 0;
            direction = d;
        }
        break;
    case RIGHT:
        if(direction == UP || direction == DOWN || direction == NULL)
        {
            speed.x = 1;
            speed.y = 0;
            direction = d;
        }
        break;
    default:
        break;
    }
}

void Snake::think(Map * map, std::vector<Snake> snakes, std::vector<Point> foods)
{
    if(direction==UP)
        setDirection(LEFT);
    else if(direction==LEFT)
        setDirection(DOWN);
    else if(direction==DOWN)
        setDirection(RIGHT);
    else if(direction==RIGHT)
        setDirection(UP);
}
