#ifndef DEF_WARRIOR
#define DEF_WARRIOR

#include "Character.hpp"

class Warrior : public Character {
public:
    Warrior(int hp, int atk, int spd, int range, bool team, int position[2]);
    Warrior(bool team, int position[2]);
    void print();
    std::string getImgString();
};

#endif