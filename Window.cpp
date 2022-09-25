#include "Window.hpp"


#include <vector>

#include <iostream>
using namespace sf;
using namespace std;

RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Titre");



//Manages the game Window
void manageWindow(Field field, Game &game) {
    
    Font font;
    Input input;
    Text text;
    loadFont(font);
    setUpText(font, text, "TEST", 30, Color::Yellow);
    game.createButtonCharacterList(field);
    
    int tour = 0;
    bool joueur1 = true;
    
    while (window.isOpen()) {
        Event event;
        
        while (window.pollEvent(event)) {
            input.eventHandler(event, window);
        }
        game.checkAction(field, input, window);
        input.setActions(false);


        window.clear(sf::Color::Black);
        window.draw(text);
        //window.draw(characterButtons[0]->getSprite());
        displayRange(game.getRangeButtons());
        createGround(window);
        displayCharacters(window, game.getCharacterButtons());
        displayActions(window, game.getActionButtons());
        
        //window.draw(button.getSprite());
        window.display();
    }
}




//Loads the font
void loadFont(Font font) {
    if (!font.loadFromFile("res/Roboto-Light.ttf")) {
        cout << "Error : Font couldn't be loaded." << endl;
    }
}

void setUpText(Font font, Text text, String txt, int size, Color color, Text::Style style1, Text::Style style2) {

    text.setFont(font);
    text.setString(txt);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setStyle(style1 | style2);
}



// Creates the board with all boxes
void createGround(RenderWindow& window) {
    int size = 150;
    int numberCases = int(WIN_WIDTH * WIN_HEIGHT / (size * size));

    Texture texture;
    string imgPath = "test.png";
    if (!texture.loadFromFile(imgPath)) {
        cout << "There was a problem reading the image : " << imgPath << endl;
    }
    for (int i = 0; i < WIN_WIDTH; i += size) {

        for (int j = 0; j < WIN_HEIGHT; j += size) {
            /*
            Rect<int> rect(Vector2i(size, size), Vector2i(i+ size /2, j+ size /2));

            RectangleShape recto(Vector2f(size, size));

            recto.setPosition(Vector2f(i, j));
            recto.setFillColor(Color::Green);
            recto.setOutlineColor(Color::Black);
            recto.setOutlineThickness(4);

            window.draw(recto);
            */
            Sprite groundCase(texture);
            groundCase.setPosition(i, j);
            window.draw(groundCase);
        }
    }   
}


void displayCharacters(sf::RenderWindow& window, std::vector<Button *> characList) {
    
    for (int i = 0; i < characList.size(); i++) {
        window.draw(characList[i]->getSprite());
        
        sf::FloatRect bounds = characList[i]->getSprite().getGlobalBounds();
        sf::RectangleShape to_draw = RectangleShape();
        Vector2f size = Vector2f(bounds.width, bounds.height);
        to_draw.setSize(size);
        to_draw.setPosition(bounds.left, bounds.top);
        to_draw.setFillColor(sf::Color::Transparent);
        to_draw.setOutlineColor(sf::Color::Red);
        to_draw.setOutlineThickness(2);
        window.draw(to_draw);
        
    }
}

void displayRange(std::vector<Button*> rangeButtons) {
    for (int i = 0; i < rangeButtons.size(); i += 1) {
        window.draw(rangeButtons[i]->getSprite());
    }
}

void displayActions(sf::RenderWindow& window, std::vector<Button*> actionButtons) {

    for (int i = 0; i < actionButtons.size(); i++) {
        window.draw(actionButtons[i]->getSprite());
    }
}