#include <iostream>
#include <cstdlib>
#include <ctime>

#define FOREVER while(true)
#define CLEAR_SCREEN system("cls")
#define PRESS_A_KEY system("pause")

#define N_BETS 100
#define ESITI 3
#define WINPROB 48

using namespace std;

int main() {
    int win_number = 0;
    int lose_number = 0;
    int money = 2;
    float avg_money = 2;

    srand(time(NULL));

    FOREVER {
        win_number = 0;
        lose_number = 0;
        for (int i=1; i<=N_BETS; i++){
            int result = rand()%100+1;
            int error = rand()%ESITI+1;
            if (result <= WINPROB) {
                cout << "Giocata la schedina n. " << i << ": " << "Vinta" <<endl;
                error = 0;
                win_number++;
                money += 2;
            }
            else {
                cout << "Giocata la schedina n. " << i << ":" << " Persa per " << error <<endl;
                lose_number++;
                money -= 2;
            }
        }
        cout << endl << "Vincenti " << win_number;
        cout << " - " << lose_number << " Perdenti" <<endl;
        cout << "Soldi attuali: " << money << endl;

        PRESS_A_KEY;
        CLEAR_SCREEN;
    }
    return 0;
}
