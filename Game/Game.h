//
// Created by Fynn on 26.11.2020.
//

#ifndef KILLTHESHIP_GAME_H
#define KILLTHESHIP_GAME_H


#include "../Ship/Ship.h"

class Game {
private:
    const static int fieldSize = 12;
    const static int shipCount = 10;
    int ships[shipCount] = {1,1,1,1,2,2,2,3,3,4};
    int field[fieldSize][fieldSize] = {};

    void display();

public:
    Game();
    void generate();
    void attack(int, int);
    bool checkFinished();
};


#endif //KILLTHESHIP_GAME_H
