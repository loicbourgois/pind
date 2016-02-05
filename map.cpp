#include "map.hpp"

#include <fstream>
#include "game.hpp"
#include <QDebug>

Map::Map(Game *parent):
    parent(parent)
{
}

Map::Map(Game * parent, std::string path) :
    parent(parent)
{
    std::ifstream input(path.c_str());
    int lineCount = 0;
    for(std::string line ; getline(input, line) ; lineCount++)
    {
        switch (lineCount) {
        case 0:
            width = std::stoi(line);
            break;
        case 1:
            height = std::stoi(line);
            break;
        default:
            std::vector<char> l;
            for(int i = 0 ; i < line.size() ; i++)
            {
                if(line[i] == '#')
                {
                    l.push_back('#');
                }
                else //if(line[i] == ' ' || line[i] == ' ')
                {
                    l.push_back(' ');
                }
            }
            map.push_back(l);
            break;
        }
    }
}

std::string Map::toString()
{
    std::string str = "";
    for(int j = 0 ; j < height ; j++)
    {
        for(int i = 0 ; i < width ; i++)
        {
            if(map[j][i] == '#')
                str.push_back('w');
            else
                str.push_back(' ');
        }
        //str.push_back('\n');
    }
    return str;
}

std::string Map::toString(std::vector<Snake> snakes)
{
    std::string str = toString();
    for(int i = 0 ; i < snakes.size() ; i++)
    {
        std::vector<Point> body = snakes[i].getBody();
        for(int j = 0 ; j < body.size() ; j++)
        {
            int x = body[j].x;
            int y = body[j].y;
            if(j)
            {
                str[y*(width) + x ]= 'b';
            }
            else
            {
                str[y*(width) + x ]= 'h';
            }
        }
    }
    return str;
}

std::string Map::toString(std::vector<Snake> snakes, std::vector<Point> foods)
{
    std::string str = toString(snakes);
    for(int i = 0 ; i < foods.size() ; i++)
        str[foods[i].y*(width) + foods[i].x ]= 'f';
    return str;
}

bool Map::caseIsEmpty(int x, int y)
{
    if(map[y][x] == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}
