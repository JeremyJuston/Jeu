#include "Archer.hpp"
#include "Character.hpp"

#include <iostream>
using namespace std;

Archer::Archer(int hp, int atk, int spd, int range, bool team, int position[2]) : Character(hp, atk, spd, range, team, position) {};
Archer::Archer(bool team, int position[2]) : Character(55, 15, 10, 10, team, position) {};

void Archer::print() {
    cout << "I am an Archer";
    Character::printChar();
}

string Archer::getImgString() {
    string archer = "archer.png";
    return archer;
}

int Archer::getMaxHp() {
    return 55;
}