#ifndef DEF_FIELD
#define DEF_FIELD

#include "Cell.hpp"
#include "Character.hpp"
#include "Archer.hpp"
#include "Warrior.hpp"
#include "Sorcerer.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>

class Field {
    protected:
        int m_width;
        int m_height;
        std::vector<Cell> m_map;
        std::vector<Character *> m_characters;
        //Item items[];

    public:
        Field();
        ~Field();
        Field(int width, int height);

        int distance(int start_x, int start_y, int end_x, int end_y);
        std::vector <std::pair<int, int>> reachableCases(int start_x, int start_y, int range);
        void addCharacter(std::string nom, bool team, int position[2]);
        void delCharacter(Character *charac);
        void print();
        void showObjects();
        std::vector<Character*> getCharacters();
        int getWidth();
        int getHeight();
        std::vector<Cell> getMap();
        void setOccupiedFromField(int x, int y, bool occupied);
        void loseHpFromField(int char_index, int damage);
 };

#endif