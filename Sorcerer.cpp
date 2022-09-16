#include "Sorcerer.hpp"
#include "Character.hpp"

#include <iostream>
using namespace std;

Sorcerer::Sorcerer(int hp, int atk, int spd, int range, bool team, int position[2]) : Character(hp, atk, spd, range, team, position) {};
Sorcerer::Sorcerer(bool team, int position[2]) : Character(40, 20, 2, 3, team, position) {};


void Sorcerer::print() {
    cout << "I am a Sorcerer";
    Character::printChar();
}

string Sorcerer::getImgString() {
    string sorcerer = "sorcerer.png";
    return sorcerer;
}

void Sorcerer::atk(Cell target) {
    
};