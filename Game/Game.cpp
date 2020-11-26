//
// Created by Fynn on 26.11.2020.
//
#include <iostream>
#include "Game.h"
#include "../Ship/Ship.h"

using namespace std;

Game::Game() {
    this->generate();
}

void Game::display() {
    for(int i = 0; i < this->fieldSize; i++) {
        for(int j = 0; j < this->fieldSize; j++) {
            if(this->field[i][j] == -1)
                cout << "X  ";
            else
                cout << "O  ";
            //cout << this->field[i][j] << "  ";
        }
        cout << endl;
    }
}

void Game::attack(int x, int y) {
    bool shipDestroyed = true;
    int fieldValue = this->field[y][x];

    if(fieldValue > 0) {
        this->field[y][x] = -1;

        for(int i = 0; i < this->fieldSize; i++)
            for(int j = 0; j < this->fieldSize; j++)
                if(this->field[i][j] == fieldValue)
                    shipDestroyed = false;

        this->display();

        if(!shipDestroyed)
            cout << endl << "Treffer!" << endl << endl;
        else
            cout << endl << "Treffer! Schiff wurde versenkt!" << endl << endl;

        return;
    }

    this->display();
    cout << endl << "Kein Treffer!" << endl << endl;
}

void Game::generate() {
    int clearArr[this->fieldSize][this->fieldSize] = {};
    memcpy(this->field, clearArr, this->fieldSize);

    for(int i = 0; i < this->shipCount; i++) {
        bool repeat = true;
        while(repeat) {
            repeat = false;

            Ship ship(this->fieldSize, this->ships[i]);
            if(ship.rotation == 1) {
                for(int j = ship.x; j < (ship.x + ship.length); j++)
                    if(this->field[ship.y][j] != 0) {
                        repeat = true;
                    }

                if(repeat == false)
                    for(int j = ship.x; j < (ship.x + ship.length); j++)
                        this->field[ship.y][j] = i + 1;
            } else {
                for(int j = ship.y; j < (ship.y + ship.length); j++)
                    if(this->field[j][ship.x] != 0) {
                        repeat = true;
                    }

                if(repeat == false)
                    for(int j = ship.y; j < (ship.y + ship.length); j++)
                        this->field[j][ship.x] = i + 1;
            }
        }
    }
}

bool Game::checkFinished() {
    bool gameFinished = true;

    for(int i = 0; i < this->fieldSize; i++)
        for(int j = 0; j < this->fieldSize; j++)
            if(this->field[i][j] > 0)
                gameFinished = false;

    if(gameFinished) {
        cout << "GEWONNEN! Wiederholen?" << endl << "0: Nein, 1: Ja" << endl;
        return true;
    }

    return false;
}
