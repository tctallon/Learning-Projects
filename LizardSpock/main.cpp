#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <numeric>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

/* -----Instructions-----
 * Play Rock, Paper Lizard, Spock against a computer.
 *
 * create random value for computer.
 *
 * run the game until you win.
 *
 * use a boolean, a void, and two int functions
 *
 * display the winner.
 *
 * -----Pseudocode----
 * Initialize functions(user input, computer, boolean)
 * Display Options for user input
 * Input User choice
 * Compute Computer choice
 * Compare User Choice and Computer Choice
 * Output Winner or Loser.
 * Repeat if User loses
 * Exit program
 */



int CompGuess(){

    srand(time(NULL));

    string guess;

    int rand_num = rand() % 5 + 1; //Random value between 1 and 5

/*    switch(rand_num){

        case 1:
            guess = 'rock';
            break;
        case 2:
            guess ='paper';
            break;
        case 3:
            guess = 'scissors';
            break;
        case 4:
            guess = 'lizard';
            break;
        case 5:
            guess = 'spock';
            break;

    };*/

    return rand_num;
};

int UserChoice(){

    int choice;

   // string guess;

    cout << "Welcome to Rock, Paper, Scissors, Lizard, Spock!" << endl;
    cout << "Select 1 for Rock\n" << "Select 2 for Paper\n" << "Select 3 for Scissors\n" << "Select 4 for Lizard\n" << "Select 5 for Spock" << endl;
    cin.clear();
    cin >> choice;

    if(choice < 1 || choice > 5){
      cout << "Your input was invalid." << endl;
    };
/*
    switch(choice){

        case 1:
            guess = 'rock';
            break;
        case 2:
            guess ='paper';
            break;
        case 3:
            guess = 'scissors';
            break;
        case 4:
            guess = 'lizard';
            break;
        case 5:
            guess = 'spock';
            break;

    };*/

    return choice;
}

bool winner(int user, int computer, bool end_game){

    if(user == computer){
        cout << "You tied! You both chose " << user << "." << endl;
    }else if(user == 1 && computer == 2){
        cout << "Paper covers rock! Try again!" << endl;
    }else if(computer == 1 && user == 2){
        cout << "Paper covers rock! You win!" << endl;
        end_game = 1;
    }else if(user == 2 && computer == 3){
        cout << "Scissors cut paper! Try Again!" << endl;
    }else if(user == 3 && computer == 2){
        cout << "Scissors cut paper! You win!" << endl;
        end_game = 1;
    }else if(user == 1 && computer == 4){
        cout << "Rock crushes lizard! You Win!" << endl;
        end_game = 1;
    }else if(computer == 1 && user == 4){
        cout << "Rock crushes lizard! Try Again!" << endl;
    }else if(user == 4 && computer == 5){
        cout << "Lizard poisons spock! You Win!" << endl;
        end_game = 1;
    }else if(user == 5 && computer == 4){
        cout << "Lizard poisons spock! Try Again!" << endl;
    }else if(user == 5 && computer == 3){
        cout << "Spock melts scissors! You win!" << endl;
        end_game=1;
    }else if (user == 3 && computer == 5){
        cout << "Spock melts scissors! Try Again" << endl;
    }else if(user == 3 && computer == 4){
        cout << "Scissors kill lizard! You win and its awful." << endl;
        end_game = 1;
    }else if(user == 4 && computer ==3){
        cout << "Scissors kill lizard! Try again" << endl;
    }else if(user == 5 && computer == 2){
        cout << "Paper disproves Spock! Try Again." << endl;
    }else if(user == 2 && computer == 5){
        cout << "Paper disproves spock, you win." << endl;
        end_game = 1;
    }else if(user == 1 && computer == 5){
        cout << "Spock vaporizes rock! You lose." << endl;
    }else if (user == 5 && computer == 1){
        cout << "Spock vaporizes rock! You win." << endl;
        end_game = 1;
    }else if( user == 1 && computer == 3){
        cout << "Rock breaks scissors. You win" << endl;
        end_game = 1;
    }else if(user == 3 && computer == 1){
        cout << "Rock breaks scissors. You lose." << endl;
    };

    return end_game;
};





int main() {

    bool end_game = 0;

    int user, computer;

    while(end_game == 0){

        user = UserChoice();

        computer = CompGuess();

        end_game = winner(user,computer,end_game);

    }

    return 0;
}
