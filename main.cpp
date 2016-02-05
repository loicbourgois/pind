#include "game.hpp"
#include<cstdlib>
#include<ctime>

#define MAP_PATH "./maps/0.map"

int main(int argc, char *argv[])
{
    std::srand(std::time(0));
    std::cout << std::string(10000, '\n' );
    Game game = Game(MAP_PATH);
    game.start();
}
