#include <iostream>

using namespace std;
class OutputManager {
public:
	static void SendCounter(int flags) {
		cout << "------------------------ \n| �������� ���: " << flags << "      | \n------------------------\n";
	}
	static void SendRules() {
		cout << "------------------------ \n| ����������: \n| ��������� - ����������� �� ���� \n| f - ��������� ����� \n| ������ - �������� ���� \n------------------------";
	}
};