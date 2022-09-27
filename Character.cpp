#include "Character.hpp"
#include <iostream>
using namespace std;

Character::Character(int hp, int atk, int spd, int range, bool team, int position[2]) : m_hp(hp), m_atk(atk), m_spd(spd), m_range(range), m_team(team) {
    m_position[0] = position[0]; 
    m_position[1] = position[1];
}

Character::~Character() {};

Character::Character(int hp, int atk, int spd, int range, bool team) : m_hp(hp), m_atk(atk), m_spd(spd), m_range(range), m_team(team) {
    m_position[0] = 0;
    m_position[1] = 0;
}

int Character::getPositionX() {
    return this->m_position[0];
}

int Character::getPositionY() {
    return this->m_position[1];
}

int Character::getHp() {
    return this->m_hp;
}

int Character::getSpd() {
    return this->m_spd;
}

int Character::getRange() {
    return this->m_range;
}

int Character::getAtk() {
    return this->m_atk;
}

bool Character::getTeam() {
    return this->m_team;
}

bool Character::operator==(Character charac) {
    return (this->m_position[0] == charac.getPositionX() && this->m_position[1] == charac.getPositionY());
}

void Character::printChar() {
    cout << " from team ";
    if (m_team == false) {
        cout << "Blue ";
    }
    else {
        cout << "Red ";
    }
    cout << "at position [" << m_position[0] << ", " << m_position[1] << "] ";
    cout << "and I have " << m_hp << " hp, " << m_atk << " attack, " << m_spd << " spd !" << endl;
}

void Character::move(int x, int y) {
    this->m_position[0] = x;
    this->m_position[1] = y;
}

void Character::loseHp(int damage) {
    this->m_hp -= damage;
}