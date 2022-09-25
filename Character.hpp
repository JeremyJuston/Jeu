#include "Cell.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#ifndef DEF_CHARACTER
#define DEF_CHARACTER

class Character {
protected:
    int m_hp;
    int m_atk;
    int m_spd;
    int m_range;
    bool m_team;
    int m_position[2];

public:
    Character(int hp, int atk, int spd, int range, bool team, int position[2]);
    Character(int hp, int atk, int spd, int range, bool team);
    ~Character();
    /*
    void showMovingRange();
    void showAttackRange();
    void move(Cell destination);
    void attack(Cell target);
    */
    bool operator==(Character charac);
    int getPositionX();
    int getPositionY();
    int getHp();
    int getMaxHp();
    int getAtk();
    int getSpd();
    int getRange();
    void printChar();
    virtual void print() {};
    virtual std::string getImgString() {
        return "";
    };
    void move(int x, int y);
    virtual void atk() {};
};
#endif