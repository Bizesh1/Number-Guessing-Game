#include<iostream>
#include<ctime>  // for time()
#include<cstdlib>
using namespace std;


struct GuessTheNumber {
    int computer;
    int player;
    char playAgain = 'y';
    int wins = 0;
    int losses = 0;
};

void displayStats(GuessTheNumber &guess) {
    cout << "\n--- Stats ---" << endl;
    cout << "Wins: " << guess.wins << " | Losses: " << guess.losses << endl;
}

int rng()
{
    return (rand() % 10) + 1;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    cout << "\nWhat are the ODDS!" << endl;
}

void input (int &inp)
{
    while (true){
        cout << "\nYour Number: ";
        cin >> inp;
        if (inp < 1 || inp > 10) {
            cout << "Invalid! Must be between 1-10." << endl;
        }else{
            break;
        }
    }
}



int main()
{
    srand(time(0));
    clearScreen();
    
    GuessTheNumber guess;

    cout << "Guess the same number as the computer and you win.\n";
    cout << "Numbers range from 1 to 10." << endl;
    system("pause");
    
    while (true)
    {
        clearScreen();
        displayStats(guess);

        guess.computer = rng();
        input(guess.player);

        cout << "\nComputer's number: " << guess.computer; 

        if (guess.player == guess.computer)
        {
            cout << "\nDing Ding Ding!! YOU WON." << endl;
            guess.wins++;
        }else
        {
            cout << "\nTry again next time." << endl;
            guess.losses++;
        }

        cout << "\n\nDo you want to play again (y/n): ";
        cin >> guess.playAgain;

        if (guess.playAgain == 'n' || guess.playAgain == 'N')
        {
            cout << "\nThanks for playing!";
            system("pause");
            break;
        }

    }

}