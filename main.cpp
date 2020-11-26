#include <iostream>
#include "Game/Game.h"

using namespace std;

int main() {
    bool repeat = true;
    int x = 0, y = 0, input = 0;
    Game game;

    cout << "KillTheShip!" << endl << "Spiel ist gestartet!" << endl << endl;

    while(repeat) {
        cout << "Attack: " << endl << " X: ";
        cin >> x;
        cout << "Y: ";
        cin >> y;
        cout << endl;

        game.attack(x, y);

        if(game.checkFinished()) {
            cin >> input;
            if(input == 1)
                game.generate();
            else
                repeat = false;
        }
    }

    return 0;
}
