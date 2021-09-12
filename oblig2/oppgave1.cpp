#include <iostream>

using namespace std;

void addressesAndContent(int i, int j, int *p, int *q) {
    cout << "Assignemt A" << endl;
    cout << "Address: " << i << ", Content: " << &i << endl;
    cout << "Address: " << j << ", Content: " << &j << endl;
    cout << "Address: " << *p << ", Content: " << &p << endl;
    cout << "Address: " << *q << ", Content: " << &q << endl;
}

void variableMutation (int *p, int *q) {
    //setter *p til ny verdi av 7
    *p = 7;
    //setter *q sin verdi til å være tidligere verdi + 3, aka 3 + 4 = 7
    *q += 4;
    //setter *q sin verdi til å vær *p (som nå er 7) + 1 = 8
    *q = *p + 1;
    //setter addressen til p til å være samme som q, som nå perker til verdi av 8
    p = q;
    cout << "Assignment B" << endl;
    //derfor får vi output "8 8" 
    cout << *p << " " << *q << endl;
}

int main () {
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    //a)
    addressesAndContent(i, j, p, q);
    //b)
    variableMutation(p, q);

    return 0;
}