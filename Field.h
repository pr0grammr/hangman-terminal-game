#ifndef HANGMAN_TERMINAL_GAME_FIELD_H
#define HANGMAN_TERMINAL_GAME_FIELD_H

#include <string>

class Field {

protected:
    int length;

public:
    Field();
    Field(int length);
    std::string render();
};


#endif
