#include <iostream>
#include <vector>
using namespace std;

const int length = 3;

//a) b)
void handleInput(string *words, string &sentence) {
    cout << "Provide 3 words" << endl;
    //gather input 
    for (int i = 0; i < length; i++) {
        cout << "Word nr" << i + 1 << ": ";
        cin >> words[i]; 
        //add as sentence
        string ending = i == length - 1 ? "." : " ";
        sentence += words[i] + ending;
    }
}

//c)
void printLengthsOf(const string *words) {
    for (int i = 0; i < length; i++) {
        cout << "Length of Word nr" << i + 1 << ": " << words[i].size() << endl;
    }
}

bool canReplace(int toBeReplaced, int lastIndex) {
    //check that we are not trying to replace outside of subjects memory allocation
    if (lastIndex < toBeReplaced) cout << "Cannot replace from position: " << toBeReplaced << " since given string last index is: " << lastIndex << endl;
    return lastIndex < toBeReplaced;
}

//e)
void replaceFromToWith(string &subject, int from, int to, string with) {
    //early return guard
    if (canReplace(from, subject.size() - 1)) return;

    //try to replace
    for (int i = from; i <= to; i++) {
        //more of the good stuff
        if (canReplace(i, subject.size() - 1)) return;
        //if all checks out
        subject.replace(i, 1, with);
    }
}

int main () {
    //word1 word2 word3
    string words[length];
    string sentence;

    //gether input
    handleInput(words, sentence);
    //print lengths of words 1,2,3 
    printLengthsOf(words);
    //print length of sentence
    cout << "Length of Sentence: " << sentence.size() << endl;

    //make copy
    string sentence2 = sentence;
    //replace characters
    replaceFromToWith(sentence2, 10, 12, "x");
    //print replaced sentence
    cout << "Sentence Copy is after replacement: " << sentence2 << endl;

    return 0;
}