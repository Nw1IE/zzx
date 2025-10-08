#include "Game.hpp"
#include <cstdlib>
#include <Windows.h>
#include <array>
#include <cstddef>
#include <cstdlib>
#include <ctime>

int main()
{
    // srand для рандома спавна какашек
    srand(static_cast<unsigned int>(time(nullptr)));

    Game game(20, 20);
    game.Run();
}
