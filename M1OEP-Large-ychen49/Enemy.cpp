#include <cstdlib>
#include "game.h"
using namespace std;

Enemy ::Enemy() : enemyTypes(normal), enemyDMG(1), enemyReward(10){
    srand(time(NULL));
};

int Enemy::getEnemyHP() const {
    return enemyHP;
}
float Enemy::getEnemyDMG() const {
    return enemyDMG;
}
int Enemy::getEnemyReward() const {
    return enemyReward;
}
Enemy::Types Enemy::getEnemyType() const {
    return enemyTypes;
}

void Enemy::setEnemyHP(int newHP) {
    enemyHP = newHP;
}
void Enemy::setEnemyDMG(float newDMG) {
    enemyDMG = newDMG;
}
void Enemy::setEnemyReward(int reward) {
    enemyReward = reward;
}
void Enemy::setEnemyType(Enemy::Types newEnemyTypes) {
    enemyTypes = newEnemyTypes;
}

void Enemy::enemyType(ostream &outs) {
    switch (rand() % 3) {
        case 0:
            setEnemyType(normal);
            setEnemyHP(10);
            setEnemyDMG(1);
            setEnemyReward(10);
            break;
        case 1:
            setEnemyType(elite);
            setEnemyHP(30);
            setEnemyDMG(4);
            setEnemyReward(30);
            break;
        case 2:
            setEnemyType(legacy);
            setEnemyHP(50);
            setEnemyDMG(8);
            setEnemyReward(50);
            break;
    }
    outs << "------------------------------" << endl;
    outs << "|The " << getEnemyType() << " appears! " <<
            "HP: " << getEnemyHP() << " DMG: " << getEnemyDMG() << "|" << endl;
    outs << "------------------------------" << endl;
}

ostream& operator << (std::ostream& outs, const Enemy::Types enemyTypes)
{
    switch (enemyTypes) {
        case Enemy::Types::normal:
            outs << "normal";
            break;
        case Enemy::Types::elite:
            outs << "elite";
            break;
        case Enemy::Types::legacy:
            outs << "legacy";
            break;
    }
}