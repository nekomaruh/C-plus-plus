#ifndef GAME_H
#define GAME_H

#include "LinkedList.h"
#include "Rules.h"
#include "Grid.h"
#include <iostream>

class Game {
private:
    LinkedList *linkedList;
    Grid *board;
public:
    Game();
    int ** getGrid();
    void addRule(int number);
    void deleteRule();
    std::string showAddedRules();
    void loadGridFile();
    void start();
    void execute();
};

#endif /* GAME_H */