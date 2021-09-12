#include <iostream>

using namespace std;

const int length = 5;

/**
 * Temp Solution no functions, no tables
**/
int main () {
    //init result variables
    double under_10 = 0, under_20 = 0, above_20 = 0;

    cout << "Provide 5 temperatures" << endl;

    //gather temps and sort
    for (int i = 0; i < length; i++) {
        double input;
        cout << "Temperature nr" << i + 1 << ": ";
        cin >> input;
        //sort our input
        if (input < 10) under_10++;
        if (input <= 20 && input >= 10) under_20++;
        if (input > 20) above_20++;
    }

    //print results
    cout << "Under 10: " << under_10 << endl;
    cout << "Between 10 and 20: " << under_20 << endl;
    cout << "Above 20: " << above_20 << endl;

    return 0;
}