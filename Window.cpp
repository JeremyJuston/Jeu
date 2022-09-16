#include "Window.hpp"
#include "Input.hpp"

#include <vector>

#include <iostream>
using namespace sf;
using namespace std;

RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Titre");
Font font;
Input input;
Text text;
std::vector<Button*> characterButtons;
std::vector<Button*> actionButtons;

//Manages the game Window
void manageWindow(Field field) {
    
    loadFont();
    setUpText(text, "TEST", 30, Color::Yellow);

    characterButtons = createButtonCharacterList(field);
    int tour = 0;
    bool joueur1 = true;
    
    while (window.isOpen()) {
        Event event;
        
        while (window.pollEvent(event)) {
            input.eventHandler(event, window);
        }
        checkAction();
        input.setActions(false);
        
        window.clear(Color::Black);

        window.draw(text);
        //window.draw(characterButtons[0]->getSprite());
        createGround(window);
        displayCharacters(window, characterButtons);
        //window.draw(button.getSprite());
        window.display();
    }
}



void checkAction() {
    if (input.getAction().left_click == true) {
        sf::Vector2i mouse_pos = input.getAction().mouse_position;
        cout << "mouse_pos : x = " << mouse_pos.x << " y = " << mouse_pos.y << endl;

        for (int char_index = 0; char_index < characterButtons.size(); char_index++) {
            cout << "char_pos : x = " << int(characterButtons[char_index]->getPosition().x) << " y = " << int(characterButtons[char_index]->getPosition().y) << endl;
            if (characterButtons[char_index]->isInSpriteRect(mouse_pos.x, mouse_pos.y)) {
                cout << "DEDANS" << endl;
            }
        }
    }

    if (input.getAction().escape == true) {
        cout << "test" << endl;
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