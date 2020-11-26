//
// Created by Fynn on 26.11.2020.
//

#include "Ship.h"
#include <stdlib.h>
#include <time.h>

Ship::Ship(int fieldSize, int length) {
    srand((unsigned) time(NULL));

    this->rotation = rand() % 2;
    this->length = length;
    if(this->rotation == 0) {
        this->x = rand() % fieldSize;
        this->y = rand() % (fieldSize - length);
    } else {
        this->x = rand() % (fieldSize - length);
        this->y = rand() % fieldSize;

    }
}