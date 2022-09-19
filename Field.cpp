#include "Field.hpp"
#include "string.h"
#include <iostream>
using namespace std;

Field::Field() : m_width(8), m_height(5) {
	vector<Cell> map;
	
	Cell cell;
	for (int i = 0; i < m_width * m_height; i++) {
		map.push_back(cell);
	}
	m_map = map;
	
	vector<Character *> characters;
	m_characters = characters;
};

Field::~Field() {};

Field::Field(int width, int height) : m_height(height), m_width(width) {
	vector<Cell> map;
	vector<Character *> characters;
	Cell cell;
	for (int i = 0; i < m_width * m_height; i++) {
		map.push_back(cell);
	}
	m_map = map;
	m_characters = characters;
};


int Field::distance(int start_x, int start_y, int end_x, int end_y) {
	return(int(abs(start_x - end_x) + abs(start_y - end_y)));
}

std::vector <std::pair<int, int>> Field::reachableCases(int start_x, int start_y, int range) {
	
	std::vector <std::pair<int, int>> reachable_cases;

	for (int x = 0; x < m_width; x++) {
		for (int y = 0; y < m_height; y++) {
			if (distance(start_x, start_y, x, y) <= range) {
				reachable_cases.push_back(std::make_pair(x, y));
			}
		}
	}
	
	return reachable_cases;
};


void Field::addCharacter(string nom, int position[2]) {
	if (nom == "archer") {
		this->m_characters.push_back(new Archer(true, position));
	} else if (nom == "warrior") {
		this->m_characters.push_back(new Warrior(true, position));
	} else if (nom == "sorcerer") {
		this->m_characters.push_back(new Sorcerer(true, position));
	} else {
		cout << "The character " << nom << " doesn't exist." << endl;
		return;
	}
	this->m_map[position[0] * this->m_height + position[1] * this->m_width].setOccupied(true);
}

void Field::delCharacter(Character *charac) {
	for (int i = 0; i < this->m_characters.size(); i++) {
		if (*charac == *this->m_characters[i]) {
			this->m_characters.erase(this->m_characters.begin()+i);
			this->m_map[charac->getPositionX() * this->m_height + charac->getPositionY() * this->m_width].setOccupied(false);
			break;
		}
	}	
}

std::vector<Character*> Field::getCharacters() {
	return this->m_characters;
}
int Field::getWidth() {
	return this->m_width;
}
int Field::getHeight() {
	return this->m_height;
}
std::vector<Cell> Field::getMap() {
	return this->m_map;
}

void Field::print() {
	for (int i = 0; i < this->m_characters.size(); i++) {
		this->m_characters[i]->print();
	}
}

void Field::showObjects() {
	for (int i = 0; i < this->m_characters.size(); i++) {
		cout << typeid(*(this->m_characters[i])).name() << endl;
	}
}