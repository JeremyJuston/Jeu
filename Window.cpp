#include "Window.hpp"

#include <vector>

#include <iostream>
using namespace sf;
using namespace std;

Font font;

//Manages the game Window
void manageWindow(RenderWindow &window, Field field) {
    
    loadFont();
    Text text;
    
    setUpText(text, "TEST", 30, Color::Yellow);
    std::vector<Button *> characterButtons = createButtonCharacterList(field);
    int tour = 0;

    bool joueur1 = true;
    bool joueur2 = false;
    
    while (window.isOpen()) {
        Event event;
        
        while (window.pollEvent(event)) {
            eventHandler(event, window);
        }
        
        window.clear(Color::Black);

        window.draw(text);
        //window.draw(characterButtons[0]->getSprite());
        createGround(window);
        displayCharacters(window, characterButtons);
        //window.draw(button.getSprite());
        window.display();
    }
}

//Handle all types of events triggered on the game Window
void eventHandler(Event event, RenderWindow& window) {
    
    if (event.type == Event::Closed) {
        window.close();
    }
}

//Loads the font
void loadFont() {
    if (!font.loadFromFile("res/Roboto-Light.ttf")) {
        cout << "Error : Font couldn't be loaded." << endl;
    }
}

void setUpText(Text text, String txt, int size, Color color, Text::Style style1, Text::Style style2) {

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
    vector<Button> ground(numberCases);

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

std::vector<Button *> createButtonCharacterList(Field field) {
    std::vector<Button *> characterButtonList;

    for (int i = 0; i < field.getCharacters().size(); i++) {
        
        Button charac(field.getCharacters()[i]->getImgString());
        
        characterButtonList.push_back(new Button(field.getCharacters()[i]->getImgString()));
        characterButtonList.back()->setPosition(field.getCharacters()[i]->getPositionX() * 150, field.getCharacters()[i]->getPositionY() * 150);
    }
    return characterButtonList;
}

void displayCharacters(sf::RenderWindow& window, std::vector<Button *> characList) {
    
    for (int i = 0; i < characList.size(); i++) {
        window.draw(characList[i]->getSprite());
    }
}