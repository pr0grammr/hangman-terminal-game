#include <iostream>

#include "Game.h"

using namespace std;

int main() {

    // initialize the game; set word and attempts
    Game hangman("Random Word", 10);

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
            cout << "This letter is not in the word. You got " << hangman.getAttempts() << " left." << endl;
            cout << hangman.renderField() << endl;
        }
    }

    // give success message to user
    if (hangman.getWord() == hangman.getField()) {
        cout << "Congrats! You made it :)" << endl;
    }


    return 0;
}