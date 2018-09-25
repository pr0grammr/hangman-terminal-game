#ifndef HANGMAN_TERMINAL_GAME_GAME_H
#define HANGMAN_TERMINAL_GAME_GAME_H

#include "Field.h"

class Game : public Field {

protected:
    int attempts;
    std::string word;
    bool alive;

public:

    std::string player;

    Game(const std::string &word, const int attempts);
    std::string getWord();
    int getAttempts();
    bool isAlive();
    bool guess(const char *letter);
};


#endif
