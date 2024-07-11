#include <iostream>
#include <iomanip>

using namespace std;
class OutputManager {
public:
    //1 - intro
    static void BestIntroduction()
    {
        printf("                                                                 00     00                          !!!!    \n");
        printf("     CCCCCCCCCC              AAA            ППППППППППППППП    EEEEEEEEEEEEEE    PPPPPPPPPPPPP      !!!!    \n");
        printf("   CCCCCCCCCCCCCC           AAAAA           ППППППППППППППП    EEEEEEEEEEEEEE    PPP        PPP     !!!!    \n");
        printf("  CCC          CCC         AA   AA          ППП         ППП    EEE               PPP          PP    !!!!    \n");
        printf("  CC                      AA     AA         ППП         ППП    EEE               PPP          PP    !!!!    \n");
        printf("  CC                     AA       AA        ППП         ППП    EEEEEEEEEE        PPP        PPP     !!!!    \n");
        printf("  CC                    AA         AA       ППП         ППП    EEE               PPPPPPPPPPPP       !!!!    \n");
        printf("  CCC          CCC     AAAAAAAAAAAAAAA      ППП         ППП    EEE               PPP                        \n");
        printf("   CCCCCCCCCCCCCC     AAAA         AAAA     ППП         ППП    EEEEEEEEEEEEEE    PPP                !!!!    \n");
        printf("     CCCCCCCCCC      AAAA           AAAA    ППП         ППП    EEEEEEEEEEEEEE    PPP                !!!!    \n");
        printf("\n\n\n");

    }
    //2 - main menu
    static void MainMenu() {
        cout << "1 - Начать игру\n"
             << "2 - Таблица рекордов\n"
             << "3 - Выход \n";

        cout << "Ваш выбор: ";
    }

    //2.1 - create game
    static void DifficultyOffer() {
        cout << "Выберите сложность: \n";
        cout << "1 - Лёгкая  (8x8) \n";
        cout << "2 - Средняя (16x16) \n";
        cout << "3 - Сложная (16x30) \n";
    }

	static void SendCounter(int flags) {
		cout << " -----------------------                        \n"
             << " | Осталось мин : " << setw(5) << flags <<  "|\n"
             << " -----------------------                        \n";
	}
	static void SendRules() {
		cout << " ------------------------------------ \n"
             << " | Управление:                        \n"
             << " | Стрелочки - перемещение по полю    \n" 
             << " | f - установка флага                \n"
             << " | Пробел - вскопать поле             \n"
             << " ------------------------------------";
	}

    //2.2 - leaderboard
    static void LeaderBoard(/*работа с файлом*/) {}

    //2.3 - meme(if no deadline)

    
};

