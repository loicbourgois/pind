#include "game.hpp"

#include <thread>
#include <fstream>
#include <QDebug>

#define WAIT 200

Game::Game()
{

}

Game::Game(std::string mapPath)
{
    map = Map(this, mapPath);
    initSnakes(mapPath);
    ai = false;
    initFood();
}

void Game::start()
{
    while(true)
    {
        for(int i = 0 ; i < snakes.size() ; i++)
        {
            snakes[i].move(&map, food, snakes);
        }
        display();
        std::this_thread::sleep_for(std::chrono::milliseconds(WAIT));
    }
}

void Game::display()
{
    std::cout << std::string(100, '\n' );
    std::cout << map.toString(snakes, food);
}

void Game::initSnakes(std::string mapPath)
{
    snakes.push_back(Snake());
    snakes.push_back(Snake(true));

    std::ifstream input(mapPath.c_str());
    int lineCount = 0;
    int x = 0;
    int y = 0;
    for(std::string line ; getline(input, line) ; lineCount++)
    {
        switch (lineCount) {
        case 0:
        case 1:
            break;
        default:
            y = lineCount - 2;
            for(int x = 0 ; x < line.size() ; x++)
            {
                switch (line[x]) {
                case 'h':
                    snakes[0].addBodyPart(x, y);
                    break;
                case 'a':
                    snakes[1].addBodyPart(x, y);
                    break;
                default:
                    break;
                }
            }
            break;
        }
    }
    std::ifstream input2(mapPath.c_str());
    for(std::string line ; getline(input2, line) ; lineCount++)
    {
        switch (lineCount) {
        case 0:
        case 1:
            break;
        default:
            y = lineCount - 2;
            for(int x = 0 ; x < line.size() ; x++)
            {
                switch (line[x]) {
                case 'b':
                    snakes[0].addBodyPart(x, y);
                    break;
                case 'i':
                    snakes[1].addBodyPart(x, y);
                    break;
                default:
                    break;
                }
            }
            break;
        }
    }
}

void Game::initFood()
{
    food.x = rand()%map.getWidth();
    food.y = rand()%map.getHeight();
    while(!checkEmpty(food))
    {
        food.x = rand()%map.getWidth();
        food.y = rand()%map.getHeight();
    }
    qDebug() << food.x << ";" << food.y;
}

bool Game::checkEmpty(Point p)
{
    bool retour = true;
    if(!map.caseIsEmpty(p.x, p.y))
    {
        retour = false;
    }
    return retour;
}
