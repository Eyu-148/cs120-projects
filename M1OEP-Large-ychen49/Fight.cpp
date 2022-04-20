#include <cstdlib>
#include "game.h"
using namespace std;

Fight::Fight() { }

void Fight::printRules(ostream &outs) {
    outs << "Let's get some 100 coins for supper but You'll run into monsters!" << endl;
    outs << "There are 3 kinds of monsters, each of them has different HP/DMG/rewards. \n";
    outs << "You have 4 skills to fight with monsters\nGood Luck!\n";
}

void Fight::skillInfo(ostream &outs) {
    outs << "You have 4 skills, enter the skill code(a, b, c, d), one skill for one turn. \n";
    outs << "a. normal attack -- perform a single attack to monster: 10 DMG \n";
    outs << "b. Power Up! -- make a double normal attack DMG: 20 DMG \n";
    outs << "c. Shield On -- use your small wooden shield to protect yourself: reduce DMG from monster by 50% \n";
    outs << "d. Healing -- heal yourself with 50% of your max HP \n";
    outs << "e. Exit this battle \n";
}

char Fight::getPlaySkill(std::ostream &outs, std::istream &ins) {
    char choice;
    skillInfo(outs);
    outs << "Type Here: ";
    ins >> choice;
    while ((choice != 'a') && (choice != 'b') && (choice != 'c') && (choice != 'd') && (choice != 'e')) {
        outs << "Invalid option. " << endl;
        skillInfo(outs);
        ins >> choice;
    }
    return choice;
}

void Fight::oneTurn(std::ostream &outs, char choice, Player &player, Enemy &enemy) {
    outs << "== Traveller's Turn ==\n";
    player.skillChoice(choice);
    float playerDMG = player.playerTotalDMG(player.getPlayerSkill(), cout);
    enemy.setEnemyHP(enemy.getEnemyHP() - playerDMG);
    if (enemy.getEnemyHP() <= 0) {
        player.setMoney(enemy.getEnemyReward());
        outs << "Success! You earn " << player.getMoney() << " coins! " << endl;
        if (player.getMoney() == player.playerMaxMoney) {
            return;
        }
        enemy.enemyType(cout);
        return;
    } else {
        outs << "Hihiman has " << enemy.getEnemyHP() << " HP left." << endl;
    }
    outs << "== Hiliman's Turn ==" << endl;
    outs << "Hihiman made " << enemy.getEnemyDMG() << " damages. " << endl;
    player.playerTotalHP(enemy.getEnemyDMG(), player.getPlayerSkill(), outs);
    if (player.getHP() <= 0) {
        outs << "Bad luck! Let's go home!" << endl;
        return;
    }
}