#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

const int length = 5;

void read_temperatures(double temperatures[], int length);

int main() {
    //init table to store temperatures
    double temperatures[length];

    //read file and add temp entries
    read_temperatures(temperatures, length);

    //table to store our result (n<10, 10<=n<=20, n>20)
    const int cases = 3;
    int result[cases];
    //sort our temps
    for (int i = 0; i < length; i++) {
        if (temperatures[i] < 10) result[0]++;
        if (temperatures[i] >= 10 && temperatures[i] <= 20) result[1]++;
        if (temperatures[i] > 20) result[2]++;
    }

    //print results
    for (int i = 0; i < cases; i++) {
        string caseText = i < 1 ? "Under 10: " : i < 2 ? "Between 10 and 20: " : "Above 20: ";
        cout << caseText << result[i] << endl;
    }
    
    //this also works
    /*cout << "Under 10: " << result[0] << endl;
    cout << "Between 10 and 20: " << result[1] << endl;
    cout << "Above 20: " << result[2] << endl;*/
    return 0;
}

void read_temperatures(double temperatures[], int length) {
    //const for file name (unchangeable variable)
    const char filename[] = "temps.dat";
    ifstream file;
    //open file ready for reading
    file.open(filename);
    if (!file) { 
        cout << "Failure to open file" << endl;
        exit(EXIT_FAILURE);
    }
    
    //variable for current temp when reading file
    double temp;
    //counter to index our temperatures and keep our file reading in bounds
    int counter = 0;
    while (file >> temp && counter < length) {
        temperatures[counter] = temp;
        counter++;
    }
    //reading over or table bounds are met = close file
    file.close();
}