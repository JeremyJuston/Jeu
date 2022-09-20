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
std::vector<Button*> rangeButtons;
Character *activeChar;
string activeAction;

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
        checkAction(field);
        input.setActions(false);
        
        window.clear(sf::Color::Black);
        window.draw(text);
        //window.draw(characterButtons[0]->getSprite());
        displayRange();
        createGround(window);
        displayCharacters(window, characterButtons);
        displayActions(window, actionButtons);
        
        //window.draw(button.getSprite());
        window.display();
    }
}

void clearDisplay() {
    actionButtons.clear();
    rangeButtons.clear();
}

void actionClicked(Field field, int act_index) {
    if (act_index == 0) {
        activeAction = "attack";
    }
    else if (act_index == 1) {
        activeAction = "move";
    }
    createRangeList(field);
    cout << activeAction << endl;
}

void characterClicked(Field field, int char_index) {
    createActions(characterButtons[char_index]);
    activeChar = field.getCharacters()[char_index];
}

void rangeClicked(Field field, int range_index) {
    int x_case = int(rangeButtons[range_index]->getPosition().x / 150);
    int y_case = int(rangeButtons[range_index]->getPosition().y / 150);
    cout << x_case << y_case << endl;

    if (field.getMap()[x_case + y_case * field.getWidth()].isOccupied() && activeAction == "move") {
        
    }
    else if (field.getMap()[x_case + y_case * field.getWidth()].isOccupied() && activeAction == "attack") {
        
    }
    else if (!field.getMap()[x_case + y_case * field.getWidth()].isOccupied() && activeAction == "move") {
        activeChar->move(x_case, y_case);
        int index_char = 0;
        for (int i = 0; i < characterButtons.size(); i++) {
            if (field.getCharacters()[i] == activeChar) {
                index_char = i;
                break;
            }
        }
        characterButtons[index_char]->setPosition(x_case * 150, y_case * 150);
    }
    else if (!field.getMap()[x_case + y_case * field.getWidth()].isOccupied() && activeAction == "attack") {

    }

}


void createRangeList(Field field) {
    int size = 150;
    int range = 0;
    Texture texture;
    string imgPath;

    if (activeAction == "attack") {
        range = activeChar->getRange();
        imgPath = "red.png";
    }  
    else {
        range = activeChar->getSpd();
        imgPath = "green.png";
    }
 
    if (!texture.loadFromFile(imgPath)) {
        cout << "There was a problem reading the image : " << imgPath << endl;
    }

    std::vector <std::pair<int, int>> cases_in_range = 
        field.reachableCases(activeChar->getPositionX(), 
                                activeChar->getPositionY(), range);

    for (int i = 0; i < cases_in_range.size(); i += 1) {
        rangeButtons.push_back(new Button(imgPath));
        rangeButtons.back()->setPosition(cases_in_range[i].first * size,
                                            cases_in_range[i].second * size);
    }
 
}

void displayRange() {
    for (int i = 0; i < rangeButtons.size(); i += 1) {
        window.draw(rangeButtons[i]->getSprite());
    }
}

void checkAction(Field field) {
    
    bool case_found = false;

    if (input.getAction().left_click == true && !case_found) {
        sf::Vector2i mouse_pos = input.getAction().mouse_position;

        for (int act_index = 0; act_index < actionButtons.size(); act_index++) {

            if (actionButtons[act_index]->isInSpriteRect(mouse_pos.x, mouse_pos.y)) {
                clearDisplay();
                actionClicked(field, act_index);
                case_found = true;
                break;
            }
        }
    }

    if (input.getAction().left_click == true && !case_found) {
        sf::Vector2i mouse_pos = input.getAction().mouse_position;

        for (int char_index = 0; char_index < characterButtons.size(); char_index++) {
            
            if (characterButtons[char_index]->isInSpriteRect(mouse_pos.x, mouse_pos.y)) {
                clearDisplay();
                characterClicked(field, char_index);
                case_found = true;
                break;
            }
        }
    }

    if (input.getAction().left_click == true && !case_found) {
        sf::Vector2i mouse_pos = input.getAction().mouse_position;
        
        for (int range_index = 0; range_index < rangeButtons.size(); range_index++) {
            
            if (rangeButtons[range_index]->isInSpriteRect(mouse_pos.x, mouse_pos.y)) {
                rangeClicked(field, range_index);
                clearDisplay();
                case_found = true;
                break;
            }
        }
    }


    if (input.getAction().left_click == true && !case_found) {
        clearDisplay();
    }

    if (input.getAction().escape == true) {
        window.close();
    }
}

void createActions(Button *charButton) {
    actionButtons.push_back(new Button("attack.png"));
    actionButtons.back()->setPosition(charButton->getPosition().x + 15, charButton->getPosition().y + 150);

    actionButtons.push_back(new Button("movement.png"));
    actionButtons.back()->setPosition(charButton->getPosition().x + 85, charButton->getPosition().y + 150);
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

void displayActions(sf::RenderWindow& window, std::vector<Button*> actionList) {

    for (int i = 0; i < actionList.size(); i++) {
        window.draw(actionList[i]->getSprite());
    }
}