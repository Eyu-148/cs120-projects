#include <iostream>
#include "game.h"
using namespace std;

/*
 * This project simulates a simple gameplay process
 * Each player will encounter enemies in different types and fight for rewards
 * player and enemy will take turns to attack and reduce the HP
 * player will receive money after killing enemy
 * the game will end in player dies or receive the largest money
 * */

void validateInput(char input);

int main() {
    Player traveller;
    Enemy hiliman;
    Fight combat;
    combat.printRules(cout);

        char ifContinue;
        cout << "Continue on adventures?(y/n) ";
        cin >> ifContinue;
        validateInput(ifContinue);

        while (ifContinue != 'n') {
            hiliman.enemyType(cout);
            char choice = combat.getPlaySkill(cout, cin);
            while (choice != 'e') {
                combat.oneTurn(cout, choice, traveller, hiliman);
                if (traveller.getHP() > 0) {
                    choice = combat.getPlaySkill(cout, cin);
                }else {
                    choice = 'e';
                }
            }
            if (traveller.getMoney() == traveller.playerMaxMoney) {
                cout << "You get it! Let's go home & enjoy supper!\n";
            } else {
                cout << "ok let's escape for safety. \n";
            }

            char ifContinue;
            cout << "Continue on adventures?(y/n) ";
            cin >> ifContinue;
            validateInput(ifContinue);
        }

    return 0;
}

void validateInput(char input) {
    while(!cin) {
        cin.clear();
        cin.ignore(50, '\n');
        cout << "Please enter an character. " << endl;
        cin >> input;
    }
}
