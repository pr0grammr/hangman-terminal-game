#ifndef HANGMAN_TERMINAL_GAME_GAME_H
#define HANGMAN_TERMINAL_GAME_GAME_H

#include <string>

class Game {

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
    std::string renderField();
    bool guess(const char *letter);
};


#endif
