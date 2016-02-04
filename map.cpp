#include "map.hpp"

#include <fstream>
#include "game.hpp"

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
        case 2:
            // TODO
            //
            break;
        default:
            std::vector<char> l;
            for(int i = 0 ; i < line.size() ; i++)
            {
                l.push_back(line[i]);
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
            str.push_back( map[j][i]);
        }
        str.push_back('\n');
    }
    return str;
}

