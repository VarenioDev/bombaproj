#include <iostream>
#include <windows.h>



using namespace std;
class cell
{

	void SetColor(int textColor, int bgColor) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
	}

    void ResetColor() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

public:
	int IsBomb;
	bool IsShowed = false;
	bool IsFlagged = false;
	bool IsUnderCursor = false;

	int MinesAround;
	void SetMines(int totalMines) {
		MinesAround = totalMines;
	}

	int Show() {
		if (IsFlagged) {
			SetColor(7, IsUnderCursor*8);
			cout << " F ";
			ResetColor();
		}
		else if (!IsShowed) {
			SetColor(7, IsUnderCursor*8);
			cout << " X ";
			ResetColor();
		}
		else if (IsBomb) {
			SetColor(7, IsUnderCursor*8);
			cout << " m ";
			ResetColor();
		}
        else {
            SetColor(MinesAround, IsUnderCursor*8);
            cout << " " << MinesAround << " ";
            ResetColor();
        }
		return 0;
	}
};