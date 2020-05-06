#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/*
 * Psuedocode
 *
 * Initialize Variables
 *
 * User Input Name and kWh
 *
 * check for valid kWh input
 *
 * Calculate costs based on kWh
 *
 * Calculate taxes from city and state rates
 *
 * Output customer name, amount due, amount after discount, total
 *
 *
 */



int main() {

    string cname = "";
    double kwh;

    cout << "Please Enter Customer Name: " << endl;
    //cin >>  cname;
    getline(cin,cname);

    cout << "Please Enter kWh Used By Customer: " << endl;
    cin.ignore();
    cin >> kwh;



    double pvalue;
    int loopcheck;
    loopcheck = 1;

    while (loopcheck == 1){

        if (kwh > 0 && kwh < 1000) {
            pvalue = 0.052 * kwh;
            loopcheck = 0;
        } else if (kwh >= 1000 && kwh < 1300) {
            pvalue = (0.052 * 1000) + ((kwh - 1000) * 0.041);
            loopcheck = 0;
        } else if (kwh >= 1300 && kwh < 2000) {
            pvalue = (0.052 * 1000) + (300 * 0.041) + ((kwh - 1300) * 0.035);
            loopcheck = 0;
        } else if (kwh >= 2000) {
            pvalue = (0.052 * 1000) + (300 * 0.041) + (700 * 0.035) + ((kwh - 2000) * 0.03);
            loopcheck = 0;
        } else {
            cout << "Please enter an accurate value for the kWh used by the customer."<< endl;
            cin >> kwh;

        }
    }


    double sr, cr, stax, ctax, dis, final;

    sr = 0.035;
    cr = 0.015;

    // Taxation
    stax = sr*pvalue;
    ctax = cr*pvalue;
    dis = pvalue - pvalue*0.12;
    final = stax + ctax + dis;

    // Outputs
    cout << "Receipt" << endl;
    cout << "Customer: " << cname << endl;
    cout << "Bill Amount: " << pvalue << endl;
    cout << "Discounted Rate: " << dis << endl;
    cout << "City Tax: " << ctax << endl;
    cout << "State Tax: " << stax << endl;
    cout << "Total Amount Due: " << final << endl;



}
