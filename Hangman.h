#ifndef HANGMAN_HANGMAN_H
#define HANGMAN_HANGMAN_H

#include <string>

#include "Player.h"

class Hangman {
private:
    std::string word_;
    short attempts_;
    bool alive_;
public:
    struct Player p1;
    struct Player p2;

    Hangman();
    void setWord(std::string word);
    std::string getWord();
    short getAttempts();
    bool isAlive();
};


#endif
