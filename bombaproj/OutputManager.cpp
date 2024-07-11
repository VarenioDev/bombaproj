#include <iostream>
#include <iomanip>

using namespace std;
class OutputManager {
public:
    //1 - intro
    static void BestIntroduction()
    {
        printf("                                                                 00     00                          !!!!    \n");
        printf("     CCCCCCCCCC              AAA            ���������������    EEEEEEEEEEEEEE    PPPPPPPPPPPPP      !!!!    \n");
        printf("   CCCCCCCCCCCCCC           AAAAA           ���������������    EEEEEEEEEEEEEE    PPP        PPP     !!!!    \n");
        printf("  CCC          CCC         AA   AA          ���         ���    EEE               PPP          PP    !!!!    \n");
        printf("  CC                      AA     AA         ���         ���    EEE               PPP          PP    !!!!    \n");
        printf("  CC                     AA       AA        ���         ���    EEEEEEEEEE        PPP        PPP     !!!!    \n");
        printf("  CC                    AA         AA       ���         ���    EEE               PPPPPPPPPPPP       !!!!    \n");
        printf("  CCC          CCC     AAAAAAAAAAAAAAA      ���         ���    EEE               PPP                        \n");
        printf("   CCCCCCCCCCCCCC     AAAA         AAAA     ���         ���    EEEEEEEEEEEEEE    PPP                !!!!    \n");
        printf("     CCCCCCCCCC      AAAA           AAAA    ���         ���    EEEEEEEEEEEEEE    PPP                !!!!    \n");
        printf("\n\n\n");

    }
    //2 - main menu
    static void MainMenu() {
        cout << "1 - ������ ����\n"
             << "2 - ������� ��������\n"
             << "3 - ����� \n";

        cout << "��� �����: ";
    }

    //2.1 - create game
    static void DifficultyOffer() {
        cout << "�������� ���������: \n";
        cout << "1 - ˸����  (8x8) \n";
        cout << "2 - ������� (16x16) \n";
        cout << "3 - ������� (16x30) \n";
    }

	static void SendCounter(int flags) {
		cout << " -----------------------                        \n"
             << " | �������� ��� : " << setw(5) << flags <<  "|\n"
             << " -----------------------                        \n";
	}
	static void SendRules() {
		cout << " ------------------------------------ \n"
             << " | ����������:                        \n"
             << " | ��������� - ����������� �� ����    \n" 
             << " | f - ��������� �����                \n"
             << " | ������ - �������� ����             \n"
             << " ------------------------------------";
	}

    //2.2 - leaderboard
    static void LeaderBoard(/*������ � ������*/) {}

    //2.3 - meme(if no deadline)

    
};

