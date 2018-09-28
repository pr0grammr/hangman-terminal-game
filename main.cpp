#include <iostream>
#include <cstdlib>
#include <random>

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
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, (int)wordlist.size() - 1);

    int randomNum = dist(mt);


    // initialize the game; set attempts
    Game hangman(wordlist[randomNum], 10);


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

        char letter;
        cout << "Type a letter: ";
        cin >> letter;

        /**
         * check if user already guessed the letter
         * call guess method
         * check if user guessed a right letter
         * print the field again
         */
        if (hangman.alreadyGuessed(&letter)) {
            cout << "You already guessed the letter '" << letter << "'. You already got " << hangman.attempts << " attempts left." << endl;
            cout << hangman.renderField() << endl;
            continue;
        }

        if (hangman.guess(&letter)) {
            cout << "Nice! The letter '" << letter << "' is in the word!" << endl << endl;
            cout << hangman.renderField() << endl;
        } else {
            hangman.attempts--;
            cout << "This letter is not in the word. You got " << hangman.attempts << " attempts left." << endl;
            cout << hangman.renderField() << endl;
        }
    }

    // give success message to user
    if (hangman.getWord() == hangman.getField()) {
        cout << "Congrats! You made it :)" << endl;
    }

    // check if user have attepts left
    if (hangman.getAttempts() == 0) {
        cout << "GAME OVER! You have no attempts left!" << endl;
        cout << "The right word was '" << hangman.getWord() << "'" << endl;
    }


    return 0;
}