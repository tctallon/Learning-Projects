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
 *
 * This program will allow the user to keep track of airline reservations.
 * The program should display the seating chart for the airplane.
 * It will use an * to indicate a seat is taken and the # to indicate the seat is available.
 * The program will also display a menu which provides the user with several options.
 * There will be two types of seats in the airplane:
 * first class and coach, each of which will have a different cost.
 * The program must make use of files, arrays and functions.
 *
 * The airplane will have 5 rows in the first class section with 4 seats in each row,
 * 2 on each side of the aisle and 10 rows in the coach section with 3
 * seats on each side of the aisle.
 * The prices for all the first class seats will be the same.
 * The first 5 rows of coach will be more expensive than the last 5 rows.
 *
 * The prices for the seats will be stored in a file called SeatPrices.txt
 * the program should read these values from the file and store the values in an array of doubles.
 *
 * The menu will provide choices to reserve a seat(s) and display the total number of seats sold
 * (indicating first class and coach), the total number of seats empty in a row,
 * the total number of seats empty in the plane (indicating first class and coach),
 * and the total amount of sales (in dollars).
 *
 * Validation: The seat requested by the user is a valid row and seat number.
 * The program should also make sure the seat is not already taken.
 *
 *
 * -----Pseudocode-----
 * Initialize Variables(prices, first_class, coach, business_class, row, col, seats etc.)
 * Output Display Menu
 * User Input Options
 * Compute User Input Option 1
 * Display Seats Available in First Class
 * User Input Seat Selections
 * Return to Menu
 * User Input Options
 * Compute User Input Option 2
 * Display Seats Available in Business
 * User Input Seat Selections
 * Return to Menu
 * User Input Options
 * Compute User Input Option 3
 * Display Seats Available in Coach
 * User Input Seat Selections
 * Return to Menu
 * Compute User Input Option 4
 * Compute Empty Seats
 * Display Empty Seats Totals
 * Return to Menu
 * Compute User Input Option 5
 * Compute Total Sales
 * Display Total Sales
 * Return to Menu
 * User Input Option 6
 * Exit Program
 *
 */

//validation for first class row
int check_fr(int row){

    while(row < 1 || row > 3){

        cout << "Your input for row was not valid, please enter a number between 1 and 3." << endl;
        cin.clear();
        cin >> row;

    };

    return row;
};

// validation for first class columns
int check_fc(int col){

    while(col < 1 || col > 4){

        cout << "Your input for row was not valid, please enter a number between 1 and 4." << endl;
        cin.clear();
        cin >> col;

    };

    return col;
};
// validation for business class and coach rows
int check_bcr(int row){

    while(row < 1 || row > 5){

        cout << "Your input for row was not valid, please enter a number between 1 and 5." << endl;
        cin.clear();
        cin >> row;

    };

    return row;
};

// validation for business class and coach columns
int check_bcc(int col){

    while(col < 1 || col > 6){

        cout << "Your input for row was not valid, please enter a number between 1 and 6." << endl;
        cin.clear();
        cin >> col;

    };

    return col;
};


int main() {

/* ----- First Attempt, I completely overcomplicated the project but I decided to leave this mess in just in case I decided to go back to my og idea.
 * ----- I planned to use three individual files instead of a vector of vectors which is much simpler and only requires one file manipulation plus a file output.
 *
 * fstream coach_seats;
    coach_seats.open("Coach.txt");
    vector<int> coach_values; // Size of array is already known, but I am using a vector in case I need to change the file at any point however the loops will be built with the file size in mind.

    if (coach_seats.is_open()){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 10; j++){
                char seat;
                cin.get(seat);
            }
        }
        coach_seats.close();
    }else{
        cout <<"Unable to open file selected." << endl;
    }
    fstream first_class;
    first_class.open("FirstClass.txt");
    */

/* --- Second Attempt
 *
 * I was going to force all the arrays into a function and output an altered array but it seems like
 * C++ is unable to perform that in a way that is manageable for me so there will be very few functions
 * outside of the main for this project.
 *
 */

    // Menu related variables

    int choice;
    int exit_program;

    //Arrays - the reason I initiliazed them this way is because I may end up swapping some open seats to closed ones for the final version

    char first_class[3][4] = {{'#','#','#','#'},{'#','#','#','#'},{'#','#','#','#'},};
    char business_class[5][6] = {{'#','#','#','#','#','#'},{'#','#','#','#','#','#'},{'#','#','#','#','#','#'},{'#','#','#','#','#','#'},{'#','#','#','#','#','#'}};
    char coach[5][6] = {{'#','#','#','#','#','#'},{'#','#','#','#','#','#'},{'#','#','#','#','#','#'},{'#','#','#','#','#','#'},{'#','#','#','#','#','#'}};

    //Occurrences Variables - I will be calculating seats available and sales using the occurrences of each # and *

    int oc_first = 0;
    int oc_business = 0;
    int oc_coach = 0;

    int oc_f;
    int oc_b;
    int oc_c;

    //Seats to reserve
    int seats;
    // vector<char> columns = {'a','b','c','d','e','f','g'};
    // vector<char> rows = {'A','B','C','D','E','F','G'};
    int col;
    int row;
    int valid_choice;


    // Seat Price variables
    fstream seat_prices;
    double seat_pricesline;
    vector<double> seat_value;
    int count_num = 0;
    seat_prices.open("SeatPrices.txt");

    if(seat_prices.is_open()){
        while(seat_prices >> seat_pricesline){
            seat_value.push_back(seat_pricesline);
           // cout << seat_pricesline << endl;
           // cout << seat_value[count_num++] << endl;

        };

    } else{
        cout << "Unable to open file." << endl;
    };




while(exit_program != 1){

    cout << "Menu: \n" << "1. Reserve a Seat in First Class\n" << "2. Reserve a Seat in Business Class\n" << "3. Reserve a Seat in Coach\n" << "4. Check Empty Seats\n" << "5. Check Total Sales\n" << "6. Exit Program" <<endl;
    cin >> choice;

    switch(choice) {

        case 1:

            cout << "You chose to reserve a seat in first class." << endl;
            cout << "How many seats would you like to reserve?" << endl;
            cin.clear();
            cin >> seats;

            while (seats < 1 || seats > 12) {
                cout << "You must select a number of seats greater than zero but less than twelve." << endl;
                cin.clear();
                cin >> seats;
            };

            cout << "Col   1 2 3 4" << endl;
            for (int i = 0; i < 3; i++) {
                cout << "Row " << (i + 1) << " ";
                for (int j = 0; j < 4; j++) {
                    char check = first_class[i][j];
                    cout << check << " ";
                };
                cout << endl;
            };

            cout << "You may reserve any seat marked with a #." << endl;
            cout << "To reserve a seat type in the corresponding row number then the corresponding column number."
                 << endl;

            for (int i = 0; i < seats; i++) {

                cout << "What row for your " << (i + 1) << " seat?" << endl;
                cin.clear();
                cin >> row;
                check_fr(row);

                cout << "What column for your " << (i + 1) << " seat?" << endl;
                cin.clear();
                cin >> col;
                check_fr(col);

                if (first_class[row - 1][col - 1] == '*') {
                    valid_choice = 0;

                    while (valid_choice == 0) {

                        cout << "The seat you selected has already been reserved, you must choose a different seat."
                             << endl;

                        cout << "What row for your " << (i + 1) << " seat?" << endl;
                        cin.clear();
                        cin >> row;
                        check_fr(row);

                        cout << "What column for your " << (i + 1) << " seat?" << endl;
                        cin.clear();
                        cin >> col;
                        check_fr(col);

                        if (first_class[row][col] == '#') {
                            valid_choice = 1;
                        };

                    };


                } else {
                    cout << "You have successfully reserved a seat." << endl;
                    first_class[row - 1][col - 1] = '*';
                };

                cout << "Col   1 2 3 4" << endl;
                for (int i = 0; i < 3; i++) {
                    cout << "Row " << (i + 1) << " ";
                    for (int j = 0; j < 4; j++) {
                        char check = first_class[i][j];
                        cout << check << " ";
                    };
                    cout << endl;
                };

            };

            cout << "Your total price will be " << (seats * seat_value[0]) << " dollars." << endl;


            break;
        case 2:

            cout << "You chose to reserve a seat in business class." << endl;

            cout << "How many seats would you like to reserve?" << endl;
            cin.clear();
            cin >> seats;

            while (seats < 1 || seats > 12) {
                cout << "You must select a number of seats greater than zero but less than twelve." << endl;
                cin.clear();
                cin >> seats;
            };

            cout << "Col   1 2 3 4 5 6" << endl;
            for (int i = 0; i < 5; i++) {
                cout << "Row " << (i + 1) << " ";
                for (int j = 0; j < 6; j++) {
                    char check = business_class[i][j];
                    cout << check << " ";
                };
                cout << endl;
            };

            cout << "You may reserve any seat marked with a #." << endl;
            cout << "To reserve a seat type in the corresponding row number then the corresponding column number."
                 << endl;

            for (int i = 0; i < seats; i++) {

                cout << "What row for your " << (i + 1) << " seat?" << endl;
                cin.clear();
                cin >> row;
                check_bcr(row);

                cout << "What column for your " << (i + 1) << " seat?" << endl;
                cin.clear();
                cin >> col;
                check_bcc(col);

                if (business_class[row - 1][col - 1] == '*') {
                    valid_choice = 0;

                    while (valid_choice == 0) {

                        cout << "The seat you selected has already been reserved, you must choose a different seat."
                             << endl;

                        cout << "What row for your " << (i + 1) << " seat?" << endl;
                        cin.clear();
                        cin >> row;
                        check_bcr(row);

                        cout << "What column for your " << (i + 1) << " seat?" << endl;
                        cin.clear();
                        cin >> col;
                        check_bcc(col);

                        if (business_class[row][col] == '#') {
                            valid_choice = 1;
                        };

                    };


                } else {
                    cout << "You have successfully reserved a seat." << endl;
                    business_class[row - 1][col - 1] = '*';
                };

                cout << "Col   1 2 3 4 5 6" << endl;
                for (int i = 0; i < 5; i++) {
                    cout << "Row " << (i + 1) << " ";
                    for (int j = 0; j < 6; j++) {
                        char check = business_class[i][j];
                        cout << check << " ";
                    };
                    cout << endl;
                };

            };

            cout << "Your total price will be " << (seats * seat_value[1]) << " dollars." << endl;

            break;
        case 3:

            cout << "You chose to reserve a seat in coach." << endl;

            cout << "How many seats would you like to reserve?" << endl;
            cin.clear();
            cin >> seats;

            while (seats < 1 || seats > 12) {
                cout << "You must select a number of seats greater than zero but less than twelve." << endl;
                cin.clear();
                cin >> seats;
            };

            cout << "Col   1 2 3 4 5 6" << endl;
            for (int i = 0; i < 5; i++) {
                cout << "Row " << (i + 1) << " ";
                for (int j = 0; j < 6; j++) {
                    char check = coach[i][j];
                    cout << check << " ";
                };
                cout << endl;
            };

            cout << "You may reserve any seat marked with a #." << endl;
            cout << "To reserve a seat type in the corresponding row number then the corresponding column number."
                 << endl;

            for (int i = 0; i < seats; i++) {

                cout << "What row for your " << (i + 1) << " seat?" << endl;
                cin.clear();
                cin >> row;
                check_bcr(row);

                cout << "What column for your " << (i + 1) << " seat?" << endl;
                cin.clear();
                cin >> col;
                check_bcc(col);

                if (coach[row - 1][col - 1] == '*') {
                    valid_choice = 0;

                    while (valid_choice == 0) {

                        cout << "The seat you selected has already been reserved, you must choose a different seat."
                             << endl;

                        cout << "What row for your " << (i + 1) << " seat?" << endl;
                        cin.clear();
                        cin >> row;
                        check_bcr(row);

                        cout << "What column for your " << (i + 1) << " seat?" << endl;
                        cin.clear();
                        cin >> col;
                        check_bcc(col);

                        if (coach[row][col] == '#') {
                            valid_choice = 1;
                        };

                    };


                } else {
                    cout << "You have successfully reserved a seat." << endl;
                    coach[row - 1][col - 1] = '*';
                };

                cout << "Col   1 2 3 4 5 6" << endl;
                for (int i = 0; i < 5; i++) {
                    cout << "Row " << (i + 1) << " ";
                    for (int j = 0; j < 6; j++) {
                        char check = coach[i][j];
                        cout << check << " ";
                    };
                    cout << endl;
                };

            };

            cout << "Your total price will be " << (seats * seat_value[2]) << " dollars." << endl;

            break;
    };
    switch(choice){
        case 4:

            cout << "You chose to check empty seats." << endl;

            /* ---- Attempt to use count, I did not account for the arrays being 2d nor the inability to pass full arrays into functions
             * oc_first = count(first_class,first_class + oc_f, '#');
            oc_business = count(business_class, business_class + oc_b, '#');
            oc_coach = count(coach, coach + oc_c, '#');

            cout << "There are " << (oc_first + oc_business + oc_coach) << " seats available." << endl;*/

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 5; j++){

                    if(first_class[i][j] == '#'){
                        oc_first = oc_first + 1;
                        // cout << oc_first << endl;
                    }
                }
            };

            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 6; j++){
                    if(business_class[i][j] == '#'){
                        oc_business = oc_business + 1;
                        // cout << oc_business << endl;
                    }
                }
            };


            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 6; j++){
                    if(coach[i][j] == '#'){
                        oc_coach = oc_coach + 1;
                        // cout << oc_coach << endl;
                    }
                }
            };

            cout << "There are " << oc_first << " seats available in first class." << endl;
            cout << "There are " << oc_business << " seats available in business class." << endl;
            cout << "There are " << oc_coach << " seats available in coach." << endl;

            break;
        case 5:

            cout << "You chose to check total sales." << endl;

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 4; j++){

                    if(first_class[i][j] == '*'){
                        oc_f = oc_f + 1;
                        //cout << oc_f << endl;
                    }else{
                        oc_f = 0;
                    };
                }
            };

            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 6; j++){
                    if(business_class[i][j] == '*'){
                        oc_b = oc_b + 1;
                        //cout << oc_b << endl;
                    }else{
                        oc_b = 0;
                    };
                }
            };


            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 6; j++){
                    if(coach[i][j] == '*'){
                        oc_c = oc_c + 1;
                        //cout << oc_c << endl;
                    }else{
                        oc_c = 0;
                    };
                }
            };

            cout << "There were " << oc_f << " seats sold in first class for a total of " << (oc_f*seat_value[0]) << " dollars."<<endl;
            cout << "There were " << oc_b << " seats sold in business class for a total of " << (oc_b*seat_value[1]) << " dollars."<<endl;
            cout << "There were " << oc_c << " seats sold in coach for a total of " << (oc_c*seat_value[2]) << " dollars."<<endl;

            break;
        case 6:

            exit_program = 1;

            break;
        default:

            break;
    };

};

    return 0;
}
