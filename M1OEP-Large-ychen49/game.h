
/*
 * This file contains 2 classes called Enemy and Player
 * */

#ifndef M1OEP_LARGE_YCHEN49_GAME_H
#define M1OEP_LARGE_YCHEN49_GAME_H

#include <iostream>
#include <vector>

/*
 * Declaration of Player class*/
class Player {
public:
    // Defalut constructor
    Player();
    // player's 4 skills
    enum skill { Normal_Attack, Power, Shield, Healing };
    skill playerSkill;
    int playerMaxMoney;

    //getters
    int getHP() const;
    float getDMG() const; //for normal attack and power skill -- dmg changes
    float getNoDMG ()const; //for healing and defend skill -- no dmg
    int getMoney() const;
    Player::skill getPlayerSkill() const;

    //setters
    void setHP(int newHP);
    void setDMG(float newDMG);
    void setMoney(int newMoney);
    void setPlayerSkill(Player::skill playerSkill);

    // requires: the char type inputed by user
    // effect: translate the input character into skill type representation
    // call: setPlayerSkill
    skill skillChoice(char skillNum);

    // requires: skill type choice, output the message
    // effect: calculate different dmg by skills and print them out to visualize
    // call: getters, getPlayerSkill
    float playerTotalDMG(Player::skill choice, std::ostream &outs);

    // requires: enemyDMG, skill type choice, output
    // effect: calculate different HP values influenced by enemy dmg and user's skill
    // call: setters
    void playerTotalHP(float enemyDMG, Player::skill choice, std::ostream &outs);

    /*Overloaded operator function*/

    // unary operator
    // effect: add amount to user's money field; substrct the HP
    Player& operator +=(int amount);
    Player& operator -=(int amount);

    // binary operator
    // effect: print the skill name
    friend std::ostream& operator << (std::ostream& outs, const skill playerSkill);

//Fields
private:
     int playerHP;
     float playerDMG;
     int money;
     int playerMaxHP;
};

class Enemy {
public:
    // default constructor
    Enemy();
    enum Types { normal, elite, legacy };
    Types enemyTypes;

    //getters
    int getEnemyHP() const;
    float getEnemyDMG() const;
    int getEnemyReward() const;
    Enemy::Types getEnemyType() const;

    //setters
    void setEnemyHP(int newHP);
    void setEnemyDMG(float newDMG);
    void setEnemyReward(int rewards);
    void setEnemyType(Enemy::Types newEnemyTypes);

    // requires: output
    // effect: create enemies in different levels randomly, print the enemy type
    // call: setters
    void enemyType(std::ostream &outs);

    /*Overloaded operator*/
    // binary operator
    // effect: print the Types name
    friend std::ostream& operator << (std::ostream& outs, const Types enemyTypes);

    // Fields
private:
    int enemyHP;
    float enemyDMG;
    int enemyReward;

};

class Fight {
public:
    // default constructor
    Fight();

    // effect: print the rules at the beginning
    void printRules(std::ostream &outs);

    // effect: print skill info before every turn
    void skillInfo(std::ostream &outs);

    // effect: validate the input from user
    // call: skillInfo
    char getPlaySkill(std::ostream &outs, std::istream &ins);

    // requires: output, char input, Player object, Enemy object
    // effect: simulate each turn
    // call: getters, setters, skillChoice, playerTotalDMG, playerTotalHP, getPlayerSkill
    void oneTurn(std::ostream &outs, char choice, Player &player, Enemy &enemy);
};

#endif //M1OEP_LARGE_YCHEN49_GAME_H
