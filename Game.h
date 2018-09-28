#ifndef HANGMAN_TERMINAL_GAME_GAME_H
#define HANGMAN_TERMINAL_GAME_GAME_H

#include <string>
#include <vector>

class Game {

protected:
    std::string word;
    bool alive;
    std::string field;
    short whitespaces;
    std::vector<char> guessedLetters;

public:

    int attempts;
    std::string player;

    Game(const std::string &word, const int attempts);
    Game(const int attempts);
    std::string getWord();
    int getAttempts();
    bool isAlive();
    std::string renderField();
    void generateField();
    std::string getField();
    bool guess(char *letter);
    std::string getGuessesLetters();
    short getWordlength();
    bool alreadyGuessed(const char *letter);
};


#endif
