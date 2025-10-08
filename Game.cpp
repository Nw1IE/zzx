#include "Game.hpp"

Game::Game(int w, int h) : width(w), height(h), gameOver(false), x(w / 2), y(h / 2), score(0), dir(STOP) {
   // буферизация
    buffer.resize(height);
    for (int i = 0; i < height; i++) {
        buffer[i] = std::string(width, ' ');
    }
    SpawnFruit();
}

void Game::SpawnFruit() {
    fruitX = rand() % (width - 2) + 1;
    fruitY = rand() % (height - 2) + 1;
}

void Game::ClearBuffer() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            buffer[i][j] = ' ';
        }
    }
}

void Game::DrawBorders() {
    // Верхняя и нижняя границы
    for (int i = 0; i < width; i++) {
        buffer[0][i] = '#';
        buffer[height - 1][i] = '#';
    }
    // Левая и правая границы
    for (int i = 0; i < height; i++) {
        buffer[i][0] = '#';
        buffer[i][width - 1] = '#';
    }
}

void Game::DrawEntities() {
    // Рисования игрока
    if (x >= 0 && x < width && y >= 0 && y < height) {
        buffer[y][x] = 'T';
    }
    // Рисования фркута 
    if (fruitX >= 0 && fruitX < width && fruitY >= 0 && fruitY < height) {
        buffer[fruitY][fruitX] = 'F';
    }
}

void Game::Draw() {
    ClearBuffer();
    DrawBorders();
    DrawEntities();

    // Очищаем консоль и выводим буфер
    system("cls");
    for (int i = 0; i < height; i++) {
        std::cout << buffer[i] << std::endl;
    }
    std::cout << "Score: " << score << std::endl;
    std::cout << "Controls: WASD to move, X to exit" << std::endl;
}

void Game::Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Game::Logic() {
    // Сохраняем предыдущую позицию
    int prevX = x, prevY = y;

   
    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    // Проверка столкновение
    if (x <= 0 || x >= width - 1 || y <= 0 || y >= height - 1) {
        x = prevX;
        y = prevY;
    }

    // Проверка сбора
    if (x == fruitX && y == fruitY) {
        score += 1;
        SpawnFruit();
    }
}

bool Game::IsGameOver() const {
    return gameOver;
}

int Game::GetScore() const {
    return score;
}

void Game::Run() {
    while (!gameOver) {
        Draw();
        Sleep(100);
        Input();
        Logic();
    }
}