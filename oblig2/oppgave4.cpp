#include <iostream>

using namespace std;

int main () {
    //all good vanlig int setup
    int a = 5;
    //denne må initialiserer, fins ingen "null referanse"
    //int &b; //bad
    int &b = a; //FIX
    //denne er fult lov, "best practice" vill være int *c = nullptr;
    int *c;
    //her prøver vi sette *c til å peke på vår uninitialliserte referanse &b, dette går ikke
    c = &b;
    //*a = *b + *c; // funker ikke side, a og b er ikke pekere, endre vil vanlig så går d
    a = b + *c; //FIX
    //&b = 2; // får opp at expression ikke er modifiable, funker med å fjerne referanse operatøren
    b = 2; //FIX
    return 0;
}