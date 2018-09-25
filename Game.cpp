#include "Game.h"
#include <sstream>

Game::Game(const std::string &word, const int attempts) {
    this->word = word;
    this->attempts = attempts;
    this->alive = true;
}

std::string Game::getWord() {
    return this->word;
}

int Game::getAttempts() {
    return this->attempts;
}

bool Game::isAlive() {
    return this->alive;
}

bool Game::guess(const char *letter) {

}

std::string Game::renderField() {
    std::stringstream field;

    field << "Player: " << this->player << std::endl;
    field << "Word length: " << this->word.length() << std::endl;
    field << "Attempts: " << this->attempts << std::endl;

    for (int i = 0; i < this->word.length(); i++) {
        if (this->word[i] == ' ') {
            field << " ";
        } else {
            field << "_";
        }
    }
    field << std::endl;
    return field.str();
}