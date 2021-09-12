#include <iostream>
#include "oppgave1.hpp" //Circle klasse fra oppgave1

using namespace std;

int main() {
 Circle circle(5);

  int area = circle.get_area();
  cout << "Arealet er lik " << endl;

  double circumference = circle.get_circumference();
  cout << "Omkretsen er lik " << circumference << endl;
}