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

using namespace std;

/* -----Instructions-----
 * The input for this program will come from a file that you will need
 * to create. The file you create will be called Random.txt. The file
 * should contain a list of random numbers (you pick the values) with
 * each number on a different line within the file, use a text editor
 * to create the file.
 *
 * The program will open the file and reads all of the numbers from the
 * file and calculates or determines the following:
 *
 * 1.Counts how many numbers were read from the file
 * 2.Determine the lowest and highest values in the file
 * 3.The average of all the numbers in the file
 * 4.The sum of all the numbers in the file (a running total)
 *
 * The program must validate that the file was opened before reading from the
 * file. If not then provide a message to the user and then the program should end.
 *
 * -----Pseudocode-----
 * Initialize variables (file, empty vector array, count for numbers, high value, low value, average, and sum)
 * Open file Random.txt
 * Verify file open
 * Input contents of file into vector array
 * Find high value
 * Display high value
 * Find low value
 * Display low value
 * Compute average
 * Display average
 * Compute Sum
 * Display sum
 */

void average_sum(vector<int> random_file){
    double sum;
    double average;

    sum = accumulate(random_file.begin(),random_file.end(), 0.0);

    average = sum / random_file.size();

    cout << "The total sum of values is " << sum << "." << endl;
    cout << "The average is " << average << "." << endl;
};
void highlow(vector<int> random_file){

    int minimum_value = *min_element(random_file.begin(),random_file.end());

    int maximum_value = *max_element(random_file.begin(),random_file.end());

    cout << "The smallest value in your file is " << minimum_value << " while the largest value is " << maximum_value << "." << endl;

};

int main() {

    vector<int> random_values;
    string line;
    int random_fileline;
    int count = 0;

    fstream random_file;
    random_file.open ("random.txt");

    if (random_file.is_open()){

        while(random_file >> random_fileline){
            random_values.push_back(random_fileline);
            // cout << random_fileline << endl;
           // cout << random_values[count++] << endl;
        }

        random_file.close();

    }else{

        cout <<"Unable to open file selected." << endl;
    }


    average_sum(random_values);
    highlow(random_values);





    return 0;
}
