#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Field.hpp"
#include "Button.hpp"
#include "Input.hpp"
#include "Game.hpp"


//Create the window
void manageWindow(Field &field, Game &game);
void loadFont(Font font);
void setUpText(Font font, sf::Text text, sf::String txt, int size, sf::Color color, sf::Text::Style style1 = sf::Text::Regular, sf::Text::Style style2 = sf::Text::Regular);

void createGround(sf::RenderWindow& window);

void displayCharacters(sf::RenderWindow& window, Field field, std::vector<Button*> characList);
void displayRange(std::vector<Button*> rangeButtons);
void displayActions(sf::RenderWindow& window, std::vector<Button*> actionButtons);


//Window constants
const int WIN_WIDTH = 1250;
const int WIN_HEIGHT = 800;

#endif
