#include <iostream>

using namespace std;
class OutputManager {
public:
	static void SendCounter(int flags) {
		cout << "------------------------ \n| Осталось мин: " << flags << "      | \n------------------------\n";
	}
	static void SendRules() {
		cout << "------------------------ \n| Управление: \n| Стрелочки - перемещение по полю \n| f - установка флага \n| Пробел - вскопать поле \n------------------------";
	}
};