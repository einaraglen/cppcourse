#include <iostream>
#include <string>
#include <cmath>  
#include <iomanip>

using namespace std;

template <typename Type> 
bool equal(Type a, Type b) {
    bool result = a == b;
    string result_text = result ? "true" : "false";
    cout << a << " vs " << b << " = " << result_text << endl;
    return a == b;
}

bool equal(double a, double b) {
    bool result = abs(a - b) < 0.00001;
    cout << fixed << showpoint;
    cout << setprecision(10);
    string result_text = result ? "true" : "false";
    cout << a << " vs " << b << " = " << result_text << endl;
    return result;
}

int main() {
    equal(0.032231123, 0.032123);
    equal(0.0000001, 0.00000001);
    equal("a", "b");
    equal("a", "a");

    return 0;
}