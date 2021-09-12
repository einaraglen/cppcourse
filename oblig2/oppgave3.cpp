#include <iostream>

using namespace std;

int main () {
    //setter klar en text buffer av 4 bokstaver
    char text[5];
    //setter opp peker til start av text buffer
    char *pointer = text;
    //definerer at vi søker for character of "e"
    char search_for = 'e';
    //tar bruker input som vår text buffer
    cin >> text;

    //går igjennom text buffer helt til vi finner char av "e"
    while (*pointer != search_for) {
        //her kan man se next level JavaScript debugging ;)
        //cout << "first " << pointer << endl;
        *pointer = search_for;
        //cout << "midt " << pointer << endl;
        pointer++;
        //cout << "etter " << pointer << endl;
    }
    //SVAR:
    //det som går feil her, er nå user input aldri inneholder "e", da vil while løkken fortsette å
    //bytte ut første char med "e", så gå til neste char i bufferen, så loopes det helt til vi kommer utenfor rekke vidde
    //av text bufferen, så vil vi bynne peke mot andre steder i minnet som ikke anngår text bufferen vår å få
    // output slik som ee▬■b og e↨■b
}