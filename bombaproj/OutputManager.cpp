#include <iostream>

using namespace std;
class OutputManager {
public:
	static void SendCounter(int flags) {
		cout << "------------------------ \n| Îñòàëîñü ìèí: " << flags << "      | \n------------------------\n";
	}
	static void SendRules() {
		cout << "------------------------ \n| Óïðàâëåíèå: \n| Ñòðåëî÷êè - ïåðåìåùåíèå ïî ïîëþ \n| f - óñòàíîâêà ôëàãà \n| Ïðîáåë - âñêîïàòü ïîëå \n------------------------";
	}

    static void BestIntroduction()
    {
        printf("                                                                 00     00                          !!!!    \n");
        printf("     CCCCCCCCCC              AAA            ÏÏÏÏÏÏÏÏÏÏÏÏÏÏÏ    EEEEEEEEEEEEEE    PPPPPPPPPPPPP      !!!!    \n");
        printf("   CCCCCCCCCCCCCC           AAAAA           ÏÏÏÏÏÏÏÏÏÏÏÏÏÏÏ    EEEEEEEEEEEEEE    PPP        PPP     !!!!    \n");
        printf("  CCC          CCC         AA   AA          ÏÏÏ         ÏÏÏ    EEE               PPP          PP    !!!!    \n");
        printf("  CC                      AA     AA         ÏÏÏ         ÏÏÏ    EEE               PPP          PP    !!!!    \n");
        printf("  CC                     AA       AA        ÏÏÏ         ÏÏÏ    EEEEEEEEEE        PPP        PPP     !!!!    \n");
        printf("  CC                    AA         AA       ÏÏÏ         ÏÏÏ    EEE               PPPPPPPPPPPP       !!!!    \n");
        printf("  CCC          CCC     AAAAAAAAAAAAAAA      ÏÏÏ         ÏÏÏ    EEE               PPP                        \n");
        printf("   CCCCCCCCCCCCCC     AAAA         AAAA     ÏÏÏ         ÏÏÏ    EEEEEEEEEEEEEE    PPP                !!!!    \n");
        printf("     CCCCCCCCCC      AAAA           AAAA    ÏÏÏ         ÏÏÏ    EEEEEEEEEEEEEE    PPP                !!!!    \n");
        printf("\n\n\n");

    }
};

