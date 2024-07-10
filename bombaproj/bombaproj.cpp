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

using namespace std;

int TOTAL_BOMBS = 5;
int COLUMNS = 5;
int ROWS = 5;

void SetColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

void StartTimer(std::chrono::steady_clock::time_point& startTime) {
    startTime = std::chrono::steady_clock::now();
}

// Функция для остановки таймера и получения прошедшего времени в секундах
double StopTimer(const std::chrono::steady_clock::time_point& startTime) {
    auto endTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedTime = endTime - startTime;
    return elapsedTime.count(); // Возвращает время в секундах (double)
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

vector<vector<cell>> InitializeMap(int rows, int cols) {
    vector<vector<cell>> cells(rows, vector<cell>(cols));
    int curBombs = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int bomb = rand() % 2;
            curBombs += bomb;
            cells[i][j].IsBomb = curBombs <= TOTAL_BOMBS ? bomb : 0;
            //cells[i][j].ShowHidden();
        }
        cout << "\n";
    }
    cout << "\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!cells[i][j].IsBomb) {
                int minesAround = 0;
                for (int x = i - 1; x < i + 2; x++) {
                    for (int y = j - 1; y < j + 2; y++) {
                        if (x >= 0 && y >= 0 && x < rows && y < cols) {
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

    //cout << (int)'1';

    cout << "Выберите сложность: \n";
    cout << "1. Лёгкая (8x8) \n" ;
    cout << "2. Средняя (16x16) \n";
    cout << "3. Сложная (16x30) \n";

    int select = _getch();
    switch (select) {
    case 49:
        COLUMNS = 8;
        ROWS = 8;
        TOTAL_BOMBS = 10;
        break;
    case 50:
        COLUMNS = 16;
        ROWS = 16;
        TOTAL_BOMBS = 40;
    case 51:
        COLUMNS = 30;
        ROWS = 16;
        TOTAL_BOMBS = 99;
    }
    system("cls");

    

    vector<vector<cell>> cells = InitializeMap(ROWS, COLUMNS);
    /*for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int bomb = rand()%2;
            curBombs += bomb;
            cells[i][j].IsBomb = curBombs <= TOTAL_BOMBS ? bomb : 0;
            cells[i][j].ShowHidden();
        }

        cout << "\n";
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (!cells[i][j].IsBomb)
            {
                int minesAround = 0;
                for (int x = i - 1; x < i+2; x++)
                    for (int y = j - 1; y < j+2; y++)
                        if (x >= 0 && y >= 0 && x < 5 && y < 5)
                            minesAround += cells[x][y].IsBomb;
                cells[i][j].SetMines(minesAround);
            }
        }
    }*/
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


