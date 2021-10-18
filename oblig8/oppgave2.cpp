#include <iostream>

using namespace std;

template <typename A, typename B>
class Pair  {
public:
    A first;
    B second;

    Pair(A first, B second) : first(first), second(second) {}
    auto sum();
    Pair<A, B> operator+(const Pair &pair);
    bool operator>(Pair &pair);
    bool operator<(Pair &pair);
};

template <typename A, typename B>
 Pair<A, B> Pair<A, B>::operator+(const Pair<A, B> &pair) {
     Pair<A, B> _pair = *this;
     _pair.first += pair.first;
     _pair.second += pair.second;
    return _pair;
}

template <typename A, typename B>
auto Pair<A, B>::sum() {
    return static_cast<A>(first) + static_cast<A>(second);
}

template <typename A, typename B>
 bool Pair<A, B>::operator>(Pair<A, B> &pair) {
     return sum() > pair.sum();
}

int main() {
  Pair<double, int> p1(3.5, 14);
  Pair<double, int> p2(2.1, 7);
  cout << "p1: " << p1.first << ", " << p1.second << endl;
  cout << "p2: " << p2.first << ", " << p2.second << endl;

  if (p1 > p2)
    cout << "p1 er størst" << endl;
  else
    cout << "p2 er størst" << endl;

  auto sum = p1 + p2;
  cout << "Sum: " << sum.first << ", " << sum.second << endl;
}

/* Utskrift:
p1: 3.5, 14
p2: 2.1, 7
p1 er størst
Sum: 5.6, 21
*/

