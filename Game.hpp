#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <string>

class Game 
{
public:
    Game(int w, int h);

    void Draw();
    void Input();
    void Logic();
    void Run();

    bool IsGameOver() const;
    int GetScore() const;
private:
    int width, height;
    bool gameOver;
    int x, y, fruitX, fruitY, score;

    enum eDir {
        STOP,
        LEFT,
        RIGHT,
        DOWN,
        UP
    };

    eDir dir;
    std::vector<std::string> buffer;

    void SpawnFruit();
    void ClearBuffer();
    void DrawBorders();
    void DrawEntities();
};