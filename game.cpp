#include "game.hpp"

#include <thread>
#include <fstream>
#include <QDebug>
#include <windows.h>
#include <thread>

#define WAIT 200
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

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

void Game::handleEvent()
{
    while(true)
    {
        //std::this_thread::sleep_for(std::chrono::milliseconds(1));
        if (GetAsyncKeyState(VK_UP) < 0)
           snakes[0].setDirection(UP);
        if (GetAsyncKeyState(VK_DOWN) < 0)
            snakes[0].setDirection(DOWN);
        if (GetAsyncKeyState(VK_LEFT) < 0)
            snakes[0].setDirection(LEFT);
        if (GetAsyncKeyState(VK_RIGHT) < 0)
           snakes[0].setDirection(RIGHT);
    }
}

void Game::start()
{
    std::thread t1(&Game::handleEvent, this);
    while(true)
    {
        for(int i = 0 ; i < snakes.size() ; i++)
        {
            snakes[i].move(&map, foods, snakes);
        }
        display();
        std::this_thread::sleep_for(std::chrono::milliseconds(WAIT));
    }
    t1.join();
}

void Game::display()
{
    std::cout << std::string(100, '\n' );
    std::string str = map.toString(snakes, foods);
    std::string str2 = "";
    for(int i = 0 ; i < str.size() ; i++)
    {
        if(!(i%32))
            str2.push_back('\n');
        str2.push_back(str[i]);
    }
    std::cout << str2;
}

void Game::initSnakes(std::string mapPath)
{
    snakes.push_back(Snake(this));
    snakes.push_back(Snake(this, true));

    std::ifstream input(mapPath.c_str());
    int lineCount = 0;
    int x = 0;
    int y = 0;
    // Get the heads
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
    // Get the bodies
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
    foods.push_back(Point());
    newFood(0);
}

void Game::newFood(int id)
{
    foods[id].x = rand()%map.getWidth();
    foods[id].y = rand()%map.getHeight();
    while(!checkEmpty(foods[id]))
    {
        foods[id].x = rand()%map.getWidth();
        foods[id].y = rand()%map.getHeight();
    }
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
