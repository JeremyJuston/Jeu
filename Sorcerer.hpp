#ifndef DEF_SORCERER
#define DEF_SORCERER

#include "Character.hpp"

class Sorcerer : public Character {
public:
    Sorcerer(int hp, int atk, int spd, int range, bool team, int position[2]);
    Sorcerer(bool team, int position[2]);
    void print();
    std::string getImgString();
};

#endif