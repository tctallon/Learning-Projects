#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


/*
 * Psuedocode
 *
 * Initialize variables value, count, guess and remain
 *
 * Display startup message
 *
 * User input guess
 *
 * check guess to see if its correct
 *
 * if no, cycle to guess again and give hint
 *
 * if yes, end with display message
 *
 *
 */



int main(){

    int value, uguess, count,remain;

    cout << "Welcome to Guessing Game 100!" << endl;

    cout << "When prompted guess a number between 1 and 100.\nYou will have 10 guesses to get the correct number.\nGood Luck!" << endl;

    count = 1;

    srand(time(0));
    value = rand()%100+1;


    while (count<=10){

        cout << "Enter a value between 1 and 100: " << endl;
        cin >> uguess;

        if(uguess < 0 || uguess > 100){

            cout << "Your guess was not valid, enter a number between 1 and 100." << endl;
            cin >> uguess;
        }
        else if (uguess != value && count<10){

            remain = 10 - count;
            cout << "You have " << remain << " guesses remaining.\n Your guess was incorrect." << endl;

            count++;

            if(uguess > value){

                cout << "Too High! Try Again!" << endl;
            }
            else if(uguess < value){

                cout << "Too Low! Try Again!" << endl;
            }


        }
        else if(uguess == value){

            if (count >=1 && count < 5) {
                cout << "Either you know the secret or you got lucky!\nYour guess was correct!" << endl;
            }
            else if (count >=5 && count < 8){
                cout << "You are pretty good at this, your guess was correct!" << endl;
            }
            else if (count >=8 && count < 10) {
                cout << "You will do better next time, your guess was correct!" << endl;
            }
            count = 11;

        }
        else if (count > 10){
            cout << "Your final guess was incorrect, please try again." << endl;
        }


    }


}