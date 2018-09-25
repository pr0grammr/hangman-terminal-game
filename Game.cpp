#include "Game.h"

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