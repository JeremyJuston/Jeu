#ifndef DEF_ARCHER
#define DEF_ARCHER

#include "Character.hpp"

class Archer : public Character {
public:
    Archer(int hp, int atk, int spd, int range, bool team, int position[2]);
    Archer(bool team, int position[2]);
    void print();
    std::string getImgString();
    int getMaxHp();
};

#endif