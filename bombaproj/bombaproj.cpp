#include <iostream>
#include "cell.cpp"
#include "Frame.cpp"
#include "OutputManager.cpp"
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#include <tuple>
#include <windows.h>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

int TOTAL_BOMBS, ROWS, COLUMNS;

int getRandomNumber(int min, int max) { // что за неописуемая суета!!???
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(min, max);
    return distr(gen);
}

void DifficultyChoose(int choose) {
    system("cls");
    switch (choose) {
    case 49:
        COLUMNS = 8;
        ROWS = 8;
        TOTAL_BOMBS = 10;
        break;
    case 50:
        COLUMNS = 16;
        ROWS = 16;
        TOTAL_BOMBS = 40;
        break;
    case 51:
        COLUMNS = 30;
        ROWS = 16;
        TOTAL_BOMBS = 99;
        break;
    default:
        cout << "ТЫ ДЕБИЛ????? Запускай заново!";
        break;
    }
}

void SetColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

void StartTimer(std::chrono::steady_clock::time_point& startTime) {
    startTime = std::chrono::steady_clock::now();
}

double StopTimer(const std::chrono::steady_clock::time_point& startTime) {
    auto endTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedTime = endTime - startTime;
    return elapsedTime.count();
}

int ShowAround(vector<vector<cell>>& cells, int x, int y) {
    for (int locX = x - 1; locX < x + 2; locX++)
        for (int locY = y - 1; locY < y + 2; locY++) {
            if (locX >= 0 && locY >= 0 && locX < ROWS && locY < COLUMNS) {
                if (cells[locX][locY].IsShowed || cells[locX][locY].IsBomb) continue;
                cells[locX][locY].IsShowed = true;
                if (cells[locX][locY].MinesAround == 0) ShowAround(cells, locX, locY);
            }
            
        }
    return 0;
}

vector<vector<cell>> InitializeMap() {
    vector<vector<cell>> cells(ROWS, vector<cell>(COLUMNS));
    int curBombs = 0;

    for (int i = 0;i < TOTAL_BOMBS;) 
    {
        int x = getRandomNumber(0, ROWS-1);
        int y = getRandomNumber(0, COLUMNS-1);

        if (!cells[x][y].IsBomb) {
            cells[x][y].IsBomb = 1;
            i++;
        }
    };

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            cells[i][j].Show();
        }
        cout << "\n";
    }
    cout << "\n";

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (!cells[i][j].IsBomb) {
                int minesAround = 0;
                for (int x = i - 1; x < i + 2; x++) {
                    for (int y = j - 1; y < j + 2; y++) {
                        if (x >= 0 && y >= 0 && x < ROWS && y < COLUMNS) {
                            minesAround += cells[x][y].IsBomb;
                        }
                    }
                }
                cells[i][j].SetMines(minesAround);
            }
        }
    }

    return cells;
}

int main()
{
    OutputManager manager;

    setlocale(LC_ALL, "Russian");
    srand(time(0));

    manager.BestIntroduction();
    manager.DifficultyOffer();
    int select = _getch();
    DifficultyChoose(select);

    vector<vector<cell>> cells = InitializeMap();

    std::chrono::steady_clock::time_point startTime;
    StartTimer(startTime);
    Frame frame(0, 0);
    while (true) {

        int arg = _getch();

        if (arg == 0 || arg == 224) {
            arg = _getch();
            switch (arg) {
            case 72:
                if(frame.y>0) frame.y -= 1;
                break;
            case 80:
                if (frame.y < ROWS-1) frame.y += 1;
                break;
            case 75:
                if (frame.x > 0) frame.x -= 1;
                break;
            case 77:
                if (frame.x < COLUMNS-1) frame.x += 1;
                break;
            }
        }
        else if (arg == 102) {
            if(!cells[frame.y][frame.x].IsShowed) cells[frame.y][frame.x].IsFlagged = !cells[frame.y][frame.x].IsFlagged;
        }
        else if (arg == 32) {
            int a = frame.y;
            int b = frame.x;
            cells[a][b].IsShowed = true;
            ShowAround(cells, a, b);
        }
        system("cls");

        int totalShowed = 0;
        int totalFlags = TOTAL_BOMBS;

        for (int i = 0; i < ROWS; i++) {
            cout << "       ";
            for (int j = 0; j < COLUMNS; j++) {
                if (i == frame.y && j == frame.x) {
                    cells[i][j].IsUnderCursor = true;
                    cells[i][j].Show();
                    cells[i][j].IsUnderCursor = false;
                }
                else cells[i][j].Show();
                totalShowed += cells[i][j].IsShowed;
                totalFlags -= cells[i][j].IsFlagged;
            }
            cout << "\n";
        }

        manager.SendCounter(totalFlags);
        manager.SendRules();

        if (ROWS*COLUMNS - totalShowed == TOTAL_BOMBS) {
            cout << "\nВы выиграли!\n" << StopTimer(startTime);
            break;
        }

        if (cells[frame.y][frame.x].IsBomb && cells[frame.y][frame.x].IsShowed) {
            cout << "\nВы проиграли!\n" << StopTimer(startTime);
            break;
        }
    }
}


