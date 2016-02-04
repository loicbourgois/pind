#include <QCoreApplication>
#include "game.hpp"

#define MAP_PATH "./maps/0.map"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Game game = Game(MAP_PATH);
    game.start();

    return a.exec();
}
