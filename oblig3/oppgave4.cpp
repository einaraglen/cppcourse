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

//f)
string getSubStringOf(string subject, int cutoff) {
    if (subject.size() - 1 < cutoff) return subject;
    return subject.substr(0, cutoff);
}

//g)
bool substringExists(string subject, string substring) {
    //https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
    //here i learned that find does infact not return -1 if substring is not found :D
    return subject.find(substring) != string::npos;
}

//h)
void printIndexesOfSubstring(string subject, string substring) {
    if (!substringExists(subject, substring)) {
        cout << "\"" << substring << "\" does not exit in \"" << subject << "\"" << endl;
        return;
    }

    int index = subject.find(substring, 0);
    while(index != string::npos) {
        cout << "\"" << substring << "\" found at " << index << endl;
        //check index after last find
        index = subject.find(substring, index + 1);
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

    //make copy d)
    string sentence2 = sentence;
    //replace characters
    replaceFromToWith(sentence2, 10, 12, "x");
    //print replaced sentence
    cout << "Sentence Copy after replacement: " << sentence2 << endl;
    //get first 5 letters of sentence
    string sentence_start = getSubStringOf(sentence, 5);
    cout << "Sentence is: " << sentence << endl;
    cout << "Sentence Start is: " << sentence_start << endl;

    string wordToCheck = "hello";
    string result = substringExists(sentence, wordToCheck) ? "Yes" : "No";
    cout << "Is \"" << wordToCheck << "\" substring of sentence: " << result << endl;

    string wordToCheck2 = "er";
    printIndexesOfSubstring(sentence, wordToCheck2);

    return 0;
}