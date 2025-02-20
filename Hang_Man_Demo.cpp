#include <iostream>
#include <stdlib.h>
using namespace std;

class clss_word {
    int guesses;
    int num_guesses;
    vector<char> letters;

    ////// private methods
    void check_correct(char k);

public:
    clss_word(string w) {
        guesses = 7;
        for (int i = 0 ; i < guesses ; i++){
            letters.push_back(w[i]);
        }
    };
    void guess();
};

void clss_word::check_correct(char k) {
    bool found = false;
    for (int i = 0 ; i < letters.size(); i++) {
        if (k == letters[i]) {
            found = true;
            // removes the matching letter from the letter vector 
            remove(letters.begin(), letters.end(), letters[i]);
            letters.pop_back();
        }
    }
    //removes a guess if given guess doesn't match anything in letter array
    if (found == false) {
        guesses--;
    }
};

void clss_word::guess() {
    //takes guesses and determins if they are correct 
    while (guesses > 0 && letters.size() > 0) {
        char usr_guess;
        cout << "guesses remaining: " << guesses << endl;
        cin >> usr_guess;
        check_correct(usr_guess);
    }
}

/// my main function
/// @return 
int main() {
    string usr_inpt;
    cout << ">>> Hangman Game! <<<" << endl << "Enter a word:";
    cin >> usr_inpt;
    clss_word W1(usr_inpt);
    W1.guess();
    return 0;
}
