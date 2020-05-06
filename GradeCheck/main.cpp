#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

/*
 * Psuedocode
 *
 * function 1
 *
 * Prompt user for input
 *
 * verify input is between 0 and 100
 *
 *
 * function 2
 *
 * find min grade
 *
 * subtract min grade from sum
 *
 * divide sum/5
 *
 * output average
 *
 * fucntion 3
 *
 * find min grade? again
 *
 */

//int GetScore();
//int FindMin (vector<double> scores);
//int CalcAverage(vector<double> scores);


int GetScore(){

    double grade;
    int check;
    check = 1;

    do {
        cout << "Please enter student's grade, the value must be between 0 and 100." << endl;
        cin >> grade;

        if (grade >= 0 && grade <=100){
            check = 0;
        }
        else{

            cout << "You did not enter a grade between 0 and 100." << endl;
        }

    } while (check == 1);

    // cout << grade << endl;

    return grade;

}

int FindMin (vector<double> scores){

    double min;

    min = *min_element(scores.begin(),scores.end());

    cout << "The lowest score was " << min << "." << endl;

    return min;
}

int CalcAverage(vector<double> scores){

    double minval, sum,avg;

    sum = accumulate(scores.begin(),scores.end(),0);
    minval = FindMin(scores);

    avg = (sum-minval)/5;

    cout << "The average score was " << avg << "." << endl;


}


int main(){

    double final;

    vector<double> scores;

    for (int a = 1; a < 7; a++){

        scores.push_back(GetScore());

    }

    // Test to insure values outputting correctly
    for (int i = 0; i < scores.size(); ++i){

        cout << scores[i] << " ";
    }
    cout << endl;

    CalcAverage(scores);

}

