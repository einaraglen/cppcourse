#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
  for (auto &e : table)
    out << e << " ";
  return out;
}

class Greater {
    int _than;

public:
    Greater(int th):_than(th){}

    bool operator()(int data) const {
        return data > _than;
    }
};

//binary predicate for a)
bool IsOdd(int data) { return data % 2 == 1; }

//binary predicate for b)
bool simillar(int i1, int i2) { return abs(i1 - i2) <= 2; }

//anonymous func for b)
void checkIntervals(vector<int> &v1, vector<int> &v2, int depth) {
    if (equal(v1.begin(), v1.begin() + depth, v2.begin(), simillar))
    cout << "b) The contents of both sequences are equal.\n";
  else
    cout << "b) The contents of both sequences differ.\n";
}

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    vector<int> v2 = {2, 3, 12, 14, 24};

    //a
    auto greater = find_if(v1.begin(), v1.end(), Greater(15));
    cout << "a) find first greater than 15 in v1: " << *greater << endl;

    //b
    checkIntervals(v1, v2, 5);
    checkIntervals(v1, v2, 4);
    //c
    cout << "c) v1 before replace: " << v1 << endl;
    replace_copy_if(v1.begin(), v1.end(), v1.begin(), IsOdd, 100);
    cout << "c) v1 after replace: " << v1 << endl;

    return 0;
}