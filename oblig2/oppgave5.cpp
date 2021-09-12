#include <iostream>

using namespace std;

int main () {
    double number = 5.1;
    double *ptr = &number;
    double &ref = number;

    //Vis tre måter å få tilordnet verdi
    //usikker med dette:
    cout << "Verdien fra variable: " << number << endl;
    cout << "Verdien fra peker: " << *ptr << endl;
    cout << "Verdien from referanse: " << ref << endl;
}