#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void findAndPrint(vector<double> list, double value) {
    auto iterator = find(list.begin(), list.end(), value);

    if (iterator != list.end() ) {
        cout << "Value " << (*iterator) << " was found" << endl;
        return;
    }

     cout << "Value " << value << " was not found" << endl;    
}

int main() {
    vector<double> numbers = {20.3, 3.1, 301.9, 54.2, 11.7};
    cout << "Front: " << numbers.front() << endl;
    cout << "Back: " << numbers.back() << endl;

    //begin gives us the iterator pointing to the start of the vector, if we plus 1 we get the next position
    numbers.emplace(numbers.begin() + 1, 99.9);

    cout << "Front: " << numbers.front() << endl;  

    //findAndPrint(numbers, 54.3); //not found
    findAndPrint(numbers, 54.2); //found

    return 0;
}