#include <iostream>
#include <cstdlib>

#include "Game.h"

using namespace std;

int main() {

    // create random list vector for EN
    vector<string> wordlist = {
            "two",
            "accident",
            "information",
            "lake",
            "committee",
            "literature",
            "marketing",
            "girlfriend",
            "employer",
            "contribution",
            "imagination",
            "bedroom",
            "distribution",
            "vehicle",
            "ratio",
            "guidance",
            "grandmother",
            "environment",
            "loss",
            "event",
            "cabinet",
            "bath",
            "director",
            "membership",
            "history",
            "requirement",
            "collection",
            "woman",
            "judgment",
            "weakness",
            "photo",
            "tongue",
            "depth",
            "poetry",
            "magazine",
            "dinner",
            "mood",
            "variation",
            "delivery",
            "country",
            "funeral",
            "situation",
            "system",
            "physics",
            "pizza",
            "river",
            "maintenance",
            "highway",
            "road",
            "fact"
    };

    // picking random word from wordlist
    short min, max, randNum;
    min = 0;
    max = wordlist.size() - 1;
    randNum = rand() % max + min;

    // initialize the game; set attempts
    Game hangman(wordlist[randNum], 10);


    // print intro message
    cout << "Welcome to Hangman, the terminal based Game!" << endl;
    cout << "Let's start!" << endl;
    cout << "Enter your name: ";

    // read username
    cin >> hangman.player;

    cout << "Hello " << hangman.player << "!" << endl;

    cout << "Let's start gaming!" << endl << endl;
    cout << hangman.renderField() << endl;

    while (hangman.isAlive()) {

        // check if user have attepts left
        if (hangman.getAttempts() == 0) {
            cout << "GAME OVER! You have no attempts left!" << endl;
            cout << "The right word was '" << hangman.getWord() << "'" << endl;
        }

        char letter;
        cout << "Type a letter: ";
        cin >> letter;

        /**
         * call guess method
         * check if user guessed a right letter
         * print the field again
         */
        if (hangman.guess(&letter)) {
            cout << "Nice! The letter '" << letter << "' is in the word!" << endl << endl;
            cout << hangman.renderField() << endl;
        } else {
            cout << "This letter is not in the word. You got " << hangman.getAttempts() << " attempts left." << endl;
            cout << hangman.renderField() << endl;
        }
    }

    // give success message to user
    if (hangman.getWord() == hangman.getField()) {
        cout << "Congrats! You made it :)" << endl;
    }


    return 0;
}