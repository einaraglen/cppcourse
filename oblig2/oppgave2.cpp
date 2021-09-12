#include <iostream>
#include <cstring>

using namespace std;

int main () {
    //er litt usikker, siden nullptr er en definert ting vi kan bruke, sp vil det være rart
    //å bytte den ut med "Dette er en tekst", så jeg tror ikke dette vil gå
    char *line = nullptr;   // eller char *line = 0;
    strcpy(line, "Dette er en tekst");
    return 0;
}