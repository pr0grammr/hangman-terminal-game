#include "Game.h"
#include <sstream>
#include <locale>
#include <iterator>
#include <algorithm>


Game::Game(const std::string &word, const int attempts) {
    this->word = word;
    this->attempts = attempts;
    this->alive = true;
    this->whitespaces = 0;

    this->generateField();
}

Game::Game(const int attempts) {
    this->attempts = attempts;
    this->alive = true;

    this->generateField();
}

std::string Game::getWord() {
    return this->word;
}

int Game::getAttempts() {
    return this->attempts;
}

bool Game::isAlive() {
    // check if word is already guessed right
    if (this->attempts == 0 || this->word == this->field) {
        this->alive = false;
    }
    return this->alive;
}

void Game::generateField() {
    for (int i = 0; i < this->word.length(); i++) {
        if (this->word[i] == ' ') {
            this->field += " ";
            this->whitespaces++;
        } else {
            this->field += "_";
        }
    }
}

std::string Game::getField() {
    return this->field;
}

bool Game::guess(char *letter) {
    bool found = false;
    std::locale loc;

    for (std::string::size_type i = 0; i < this->word.length(); i++) {
        this->word[i] = std::tolower(this->word[i], loc);
    }

    *letter = std::tolower(*letter, loc);
    this->guessedLetters.push_back(*letter);

    /**
     * iterate over each letter and check if the letter is equal to the user's one
     * replacing field with the letter on each position
     */
    for (int i = 0; i < this->word.length(); i++) {
        if (*letter == this->word[i]) {
            this->field[i] = *letter;
            found = true;
        }
    }

    return found;
}

std::string Game::renderField() {
    std::stringstream field;

    field << "PLAYER: " << this->player << std::endl;
    field << "WORD LENGTH: " << this->getWordlength() << std::endl;
    field << "ATTEMPTS: " << this->attempts << std::endl;
    field << "GUESSED LETTERS: " << this->getGuessesLetters() << std::endl;

    field << std::endl;

    field << this->field;

    field << std::endl;
    return field.str();
}

bool Game::alreadyGuessed(const char* letter) {
    if (std::find(this->guessedLetters.begin(), this->guessedLetters.end(), *letter) != this->guessedLetters.end()) {
        return true;
    } else {
        return false;
    }
}

std::string Game::getGuessesLetters() {
    std::stringstream letters;

    for (int i = 0; i < this->guessedLetters.size(); i++) {
        if (i == this->guessedLetters.size() - 1) {
            if (this->alreadyGuessed(&this->guessedLetters[i])) {
                letters << this->guessedLetters[i];
            }
        } else {
            if (this->alreadyGuessed(&this->guessedLetters[i])) {
                letters << this->guessedLetters[i] << ", ";
            }
        }
    }

    return letters.str();
}

short Game::getWordlength() {
    return (short)this->word.length() - this->whitespaces;
}