#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Field.hpp"
#include "Button.hpp"

//Create the window
void manageWindow(sf::RenderWindow& window, Field field);
void eventHandler(sf::Event event, sf::RenderWindow& window);
void loadFont();
void setUpText(sf::Text text, sf::String txt, int size, sf::Color color, sf::Text::Style style1 = sf::Text::Regular, sf::Text::Style style2 = sf::Text::Regular);
void createGround(sf::RenderWindow &window);
std::vector<Button *> createButtonCharacterList(Field field);
void displayCharacters(sf::RenderWindow& window, std::vector<Button *> characList);


//Window constants
const int WIN_WIDTH = 1200;
const int WIN_HEIGHT = 750;

#endif
