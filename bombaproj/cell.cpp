#include <iostream>

using namespace std;
class cell
{
public:
	int IsBomb;
	bool IsShowed = false;
	int MinesAround;
	int SetMines(int totalMines) {
		MinesAround = totalMines;
		return 0;
	}
	int ShowHidden() {
		std::cout << "X";
		return 0;
	}
	int Show() {
		if (!IsShowed) std::cout << "X";
		else if (IsBomb) std::cout << "m";
		else std::cout << MinesAround;
		return 0;
	}
};