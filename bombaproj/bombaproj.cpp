#include <iostream>
#include "cell.cpp"
#include <ctime>
#include <string>

using namespace std;

int TOTAL_BOMBS = 5;

int ShowAround(cell(&cells)[5][5], int x, int y) {
    for (int locX = x - 1; locX < x + 2; locX++)
        for (int locY = y - 1; locY < y + 2; locY++) {
            if (locX >= 0 && locY >= 0 && locX < 5 && locY < 5) {
                if (cells[locX][locY].IsShowed || cells[locX][locY].IsBomb) continue;
                cells[locX][locY].IsShowed = true;
                if (cells[locX][locY].MinesAround == 0) ShowAround(cells, locX, locY);
            }
            
        }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int curBombs = 0;

    cell cells[5][5];
    for (int i = 0; i < 5; i++) {
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
    }

    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 6) break;
        cells[a][b].IsShowed = true;
        ShowAround(cells, a, b);

        int totalShowed = 0;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cells[i][j].Show();
                totalShowed += cells[i][j].IsShowed;
            }
            cout << "\n";
        }

        if (25 - totalShowed == TOTAL_BOMBS) {
            cout << "Вы выиграли!";
            break;
        }

        if (cells[a][b].IsBomb) {
            cout << "Вы проиграли!";
            break;
        }
    }
}


