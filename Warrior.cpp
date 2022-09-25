#include "Warrior.hpp"
#include "Character.hpp"

#include <iostream>
using namespace std;

Warrior::Warrior(int hp, int atk, int spd, int range, bool team, int position[2]) : Character(hp, atk, spd, range, team, position) {};
Warrior::Warrior(bool team, int position[2]) : Character(100, 15, 2, 1, team, position) {};


void Warrior::print() {
    cout << "I am a Warrior";
    Character::printChar();
}

string Warrior::getImgString() {
    string warrior = "warrior.png";
    return warrior;
}

int Warrior::getMaxHp() {
    return 100;
}