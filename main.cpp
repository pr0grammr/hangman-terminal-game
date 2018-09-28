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

    // set colors for output
    struct Colors colors;
    colors.red = "\033[31;m";
    colors.green = "\033[32;m";
    colors.blue = "\033[34;m";
    colors.white = "\033[37;m";
    colors.bold = "\033[1;m";
    colors.magenta = "\033[35;m";
    colors.cyan = "\033[36;m";
    colors.yellow = "\033[33;m";
    colors.bg_green = "\033[42;m";
    colors.bg_red = "\033[41;m";
    colors.bg_blue = "\033[44;m";
    colors.none = "\033[0;m";

    hangman.colors = colors;


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
            cout << hangman.colors.bg_blue << "You already guessed the letter '" << letter << "'. You still got " << hangman.attempts << " attempts left." << hangman.colors.none << endl;
            cout << hangman.renderField() << endl;
            continue;
        }

        if (hangman.guess(&letter)) {
            cout << hangman.colors.bg_green << "Nice! The letter '" << letter << "' is in the word!" << hangman.colors.none << endl;
            cout << hangman.renderField() << endl;
        } else {
            hangman.attempts--;
            cout << hangman.colors.bg_red << "The letter '" << letter << "' is not in the word. You got " << hangman.attempts << " attempts left." << hangman.colors.none << endl;
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