#include "Hangman.h"

Hangman::Hangman() {
    this->attempts_ = 5;
}

void Hangman::setWord(std::string word) {
    this->word_ = word;
}

std::string Hangman::getWord() {
    return this->word_;
}

short Hangman::getAttempts() {
    return this->attempts_;
}

bool Hangman::isAlive() {
    return this->alive_;
}

