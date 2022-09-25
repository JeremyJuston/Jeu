#include "Window.hpp"
#include "Field.hpp"
#include "Archer.hpp"
#include "Sorcerer.hpp"
#include "Warrior.hpp"


using namespace sf;
int main()
{
    
    
    Field field(8, 5);
    int pos[2] = { 0, 1 };
    int posi[2] = { 1, 1 };

    field.addCharacter("archer", posi);
    field.addCharacter("warrior", pos);
    
    field.print();
    field.showObjects();
    
    field.getCharacters()[0]->move(1, 0);
    field.print();
    field.showObjects();
    Game game;
    manageWindow(field, game);
    return 0;
}