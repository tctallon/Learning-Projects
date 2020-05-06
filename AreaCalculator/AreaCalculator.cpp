#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


// function for checking values for validity

int validarg(double a){

    while (a<=0){

        cout << "Your input was invalid, the input must be greater than zero." << endl;
        cout << "Enter a new value greater than zero: " << endl;
        cin >> a;
    }

}

/*

Psuedocode

Menu-driven program

Display options (circle, rectangle, triangle, trapezoid, or sphere)

User Input for Choice

User Input for variables needed to calculate

Calculate choice

Display various values from each choice

*/

int main() {

    int choice;
    const double PI = 3.14159;

    cout << "Welcome to Generic Calculator 5000!" << endl;

    cout << "Select a Shape from the Choices Listed by Entering the Corresponding Values." << endl;

    cout << "1. Circle\n2. Rectangle\n3. Triangle\n4. Trapezoid\n5. Sphere\n6. Exit" << endl;

    cin >> choice;

    switch (choice){
        case 1:

            double ac;
            cout << "Your choice was a Circle." << endl;
            double r;
            cout << "What is the radius of the circle?" << endl;
            cin >> r;
            validarg(r);
            ac = PI*pow(r,2);
            cout << "The area of the circle is " << ac << endl;

            break;

        case 2:

            cout << "Your choice was a Rectangle." << endl;
            double length, width;
            double ra;
            cout << "What is the length of the rectangle?" << endl;
            cin >> length;
            validarg(length);
            cout << "What is the width of the rectangle?" << endl;
            cin >> width;
            validarg(width);
            ra = length*width;
            cout << "The area of the rectangle is " << ra << endl;

            break;

        case 3:

            cout << "Your choice was a Triangle." << endl;
            double base, height;
            double ta;
            cout << "What is the base size of the triangle?" << endl;
            cin >> base;
            validarg(base);
            cout << "What is the height of the triangle?" << endl;
            cin >> height;
            validarg(height);
            ta = base*height*0.5;
            cout << "The area of the triangle is " << ta << endl;

            break;

        case 4:

            cout << "Your choice was a Trapezoid." << endl;
            double b1,b2,height2;
            double tza;
            cout << "What is the first base size of the trapezoid?" << endl;
            cin >> b1;
            validarg(b1);
            cout << "What is the second base size of the trapezoid?" << endl;
            cin >> b2;
            validarg(b2);
            cout << "What is the height of the trapezoid?" << endl;
            cin >> height2;
            validarg(height2);
            tza = height2*0.5*(b1 + b2);
            cout << "The area of the trapezoid is " << tza << endl;

            break;

        case 5:

            cout << "Your choice was a Sphere." << endl;
            double r2;
            double sa;
            cout << "What is the radius of the sphere?" << endl;
            cin >> r2;
            validarg(r2);
            sa = 4*PI*pow(r2,2);
            cout << "The area of the sphere is " << sa << endl;

            break;

        case 6:
            cout << "You chose to exit the program" << endl;
            break;


    }


    return 0;
};
