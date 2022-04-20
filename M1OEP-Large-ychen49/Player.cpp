#include "game.h"
using namespace std;

Player ::Player() : playerSkill(Normal_Attack), playerHP(40), money(0) {
    playerMaxHP = 40;
    playerDMG = 10;
    playerMaxMoney = 100;
}

int Player::getHP() const {
    return playerHP;
}
float Player::getDMG() const {
    return playerDMG;
}
float  Player::getNoDMG() const {
    return 0;
}
int Player::getMoney() const{
    return money;
}
Player::skill Player::getPlayerSkill() const {
    return playerSkill;
}


void Player::setHP(int newHP) {
    playerHP = newHP;
}
void Player::setDMG(float newDMG) {
    if (newDMG > 0) {
        playerDMG = newDMG;
    } else {
        return;
    }
}
void Player::setMoney(int newMoney) {
    money += newMoney;
}
void Player::setPlayerSkill(Player::skill newPlayerSkill) {
    playerSkill = newPlayerSkill;
}

Player::skill Player::skillChoice(char skillNum) {
    switch (skillNum) {
        case 'a':
            setPlayerSkill(Normal_Attack);
            break;
        case 'b':
            setPlayerSkill(Power);
            break;
        case 'c':
            setPlayerSkill(Shield);
            break;
        case 'd':
            setPlayerSkill(Healing);
            break;
    }
    return skill::Normal_Attack;
}

float Player::playerTotalDMG(Player::skill choice, ostream &outs) {
    // reset the damage as the damage should be a constant
    setDMG(10);
    switch (choice) {
        case Normal_Attack:
            setDMG(playerDMG);
            break;
        case Power:
            setDMG(playerDMG*2);
            break;
        case Shield:
            setDMG(0);
            break;
        case Healing:
            setDMG(0);
            if (playerHP > playerMaxHP) {
                setHP(playerMaxHP);
            } else {
                setHP((playerHP + playerMaxHP * 0.5));
                if (playerHP > playerMaxHP) {
                    setHP(playerMaxHP);
                }
            }
    }
    outs << "You choose " << getPlayerSkill() << endl;
    if (getPlayerSkill()==Normal_Attack || getPlayerSkill() == Power) {
        outs << "You made " << getDMG() << " damage. " << endl;
        return getDMG();
    } else {
        outs << "You made 0 damage. " << endl;
        return getNoDMG();
    }
}

void Player::playerTotalHP(float enemyDMG, Player::skill choice, ostream &outs) {
    switch (choice) {
        case Normal_Attack:
            setHP((playerHP - enemyDMG));
            break;
        case Power:
            setHP((playerHP - enemyDMG));
            break;
        case Shield:
            setHP(playerHP - enemyDMG*0.5);
            break;
        case Healing:
            break;
    }
    outs << "You now have " << getHP() << " HP. " << endl;
}

Player& Player::operator +=(int amount) {
    int currentMoney = getMoney();
    currentMoney += amount;
    return *this;
}
Player& Player::operator -=(int amount) {
    playerHP -= amount;
    return *this;
}

ostream& operator << (std::ostream& outs, const Player::skill playerSkill) {
    switch (playerSkill) {
        case Player::skill::Normal_Attack:
            outs << "normal attack";
            break;
        case Player::skill::Power:
            outs << "Power Up!";
            break;
        case Player::skill::Shield:
            outs << "Shield On.";
            break;
        case Player::skill::Healing:
            outs << "Healing";
            break;
    }
}

