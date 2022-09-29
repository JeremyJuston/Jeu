#include "Game.hpp"

using namespace std;

Game::Game() {
	std::vector<Button*> m_characterButtons;
	std::vector<Button*> m_actionButtons;
	std::vector<Button*> m_rangeButtons;
	Character* m_activeChar;
	std::string m_activeAction;
}

Game::~Game() {

}


std::vector<Button*> Game::getCharacterButtons() {
	return this->m_characterButtons;
}

std::vector<Button*> Game::getActionButtons() {
	return this->m_actionButtons;
}

std::vector<Button*> Game::getRangeButtons() {
	return this->m_rangeButtons;
}

Character* Game::getActiveChar() {
	return this->m_activeChar;
}

std::string Game::getActiveAction() {
	return this->m_activeAction;
}


void Game::setCharacterButtons(std::vector<Button*> charButtons) {
	this->m_characterButtons = charButtons;
}

void Game::setActionButtons(std::vector<Button*> actionButtons) {
	this->m_actionButtons = actionButtons;
}

void Game::setRangeButtons(std::vector<Button*> rangeButtons) {
	this->m_rangeButtons = rangeButtons;
}

void Game::setActiveChar(Character* actChar) {
	this->m_activeChar = actChar;
}

void Game::setActiveAction(std::string actAction) {
	this->m_activeAction = actAction;
}



void Game::checkAction(Field &field, Input input, RenderWindow &window) {
    bool case_found = false;

    // Test actions 
    if (input.getAction().left_click == true && !case_found) {
        sf::Vector2i mouse_pos = input.getAction().mouse_position;
        
        for (int act_index = 0; act_index < this->getActionButtons().size(); act_index++) {

            if (this->getActionButtons()[act_index]->isInSpriteRect(mouse_pos.x, mouse_pos.y)) {
                cout << "test act" << endl;
                this->clearDisplay();
                this->actionClicked(field, act_index);
                case_found = true;
                break;
            }
        }
    }

    // Test characters
    if (input.getAction().left_click == true && !case_found && this->getActiveAction() != "attack") {
        sf::Vector2i mouse_pos = input.getAction().mouse_position;

        for (int char_index = 0; char_index < this->getCharacterButtons().size(); char_index++) {

            if (this->getCharacterButtons()[char_index]->isInSpriteRect(mouse_pos.x, mouse_pos.y)) {
                cout << "test char" << endl;
                this->clearDisplay();
                this->characterClicked(field, char_index);
                case_found = true;
                break;
            }
        }
    }

    // Test ranges 
    if (input.getAction().left_click == true && !case_found) {
        sf::Vector2i mouse_pos = input.getAction().mouse_position;

        for (int range_index = 0; range_index < this->getRangeButtons().size(); range_index++) {

            if (this->getRangeButtons()[range_index]->isInSpriteRect(mouse_pos.x, mouse_pos.y)) {
                cout << "test ran" << endl;
                this->rangeClicked(field, range_index);
                this->clearDisplay();
                case_found = true;
                this->setActiveAction("");
                break;
            }
        }
    }


    if (input.getAction().left_click == true && !case_found) {
        this->clearDisplay();
    }

    if (input.getAction().escape == true) {
        window.close();
    }
}

void Game::clearDisplay() {
    this->m_actionButtons.clear();
    this->m_rangeButtons.clear();
}

void Game::actionClicked(Field field, int act_index) {
    if (act_index == 0) {
        this->setActiveAction("attack");
    }
    else if (act_index == 1) {
        this->setActiveAction("move");
    }
    createRangeButtons(field);
    cout << this->getActiveAction() << endl;
}

void Game::characterClicked(Field field, int char_index) {
    createActions(this->getCharacterButtons()[char_index]);
    this->setActiveChar(field.getCharacters()[char_index]);
}

int Game::retrieveCharIndex(Field field) {
    int index_char = 0;
    for (int i = 0; i < this->getCharacterButtons().size(); i++) {
        if (field.getCharacters()[i] == this->getActiveChar()) {
            index_char = i;
            break;
        }
    }
    return index_char;
}

void Game::createActions(Button* charButton) {
    std::vector<Button*> actionButtons;

    actionButtons.push_back(new Button("attack.png"));
    actionButtons.back()->setPosition(charButton->getPosition().x + 15, charButton->getPosition().y + 150);

    actionButtons.push_back(new Button("movement.png"));
    actionButtons.back()->setPosition(charButton->getPosition().x + 85, charButton->getPosition().y + 150);

    this->setActionButtons(actionButtons);
}

void Game::rangeClicked(Field &field, int range_index) {
    int x_case = int(this->getRangeButtons()[range_index]->getPosition().x / 150);
    int y_case = int(this->getRangeButtons()[range_index]->getPosition().y / 150);


    if (field.getMap()[x_case + y_case * field.getWidth()].isOccupied() && this->getActiveAction() == "move") {
    
    }

    else if (field.getMap()[x_case + y_case * field.getWidth()].isOccupied() && this->getActiveAction() == "attack") {

        int char_index = 0;
        for (char_index; char_index < field.getCharacters().size(); char_index++) {
            
            if (field.getCharacters()[char_index]->getPositionX() == x_case &&
                field.getCharacters()[char_index]->getPositionY() == y_case) {
                break;
            }
        }

        if (this->getActiveChar()->getTeam() != field.getCharacters()[char_index]->getTeam()) {
            field.loseHpFromField(char_index, this->getActiveChar()->getAtk());
        }

        this->verifyDeaths(field);
    }

    else if (!field.getMap()[x_case + y_case * field.getWidth()].isOccupied() && this->getActiveAction() == "move") {

        field.setOccupiedFromField(this->getActiveChar()->getPositionX(),
                                    this->getActiveChar()->getPositionY(), false);
        this->getActiveChar()->move(x_case, y_case);
        int index_char = this->retrieveCharIndex(field);

        field.setOccupiedFromField(x_case, y_case, false);
        this->getCharacterButtons()[index_char]->setPosition(x_case * 150, y_case * 150);
    }

    else if (!field.getMap()[x_case + y_case * field.getWidth()].isOccupied() && this->getActiveAction() == "attack") {
    
    }
}

void Game::verifyDeaths(Field &field) {
    
    bool dead = true;

    while (dead) {
        dead = false;

        for (int char_index = 0; char_index < field.getCharacters().size(); char_index++) {

            if (field.getCharacters()[char_index]->getHp() <= 0) {
                field.setOccupiedFromField(field.getCharacters()[char_index]->getPositionX(),
                                            field.getCharacters()[char_index]->getPositionY(),
                                            false);
                field.delCharacter(field.getCharacters()[char_index]);
                this->createCharacterButtons(field);
                dead = true;
                break;
            }
        }
    }
}


void Game::createRangeButtons(Field field) {
    int size = 150;
    int range = 0;
    Texture texture;
    string imgPath;
    std::vector<Button*> rangeButtons;

    if (this->getActiveAction() == "attack") {
        range = this->getActiveChar()->getRange();
        imgPath = "red.png";
    }
    else {
        range = this->getActiveChar()->getSpd();
        imgPath = "green.png";
    }

    if (!texture.loadFromFile(imgPath)) {
        cout << "There was a problem reading the image : " << imgPath << endl;
    }

    std::vector <std::pair<int, int>> cases_in_range =
        field.reachableCases(this->getActiveChar()->getPositionX(),
            this->getActiveChar()->getPositionY(), range);

    for (int i = 0; i < cases_in_range.size(); i += 1) {
        rangeButtons.push_back(new Button(imgPath));
        rangeButtons.back()->setPosition(cases_in_range[i].first * size,
            cases_in_range[i].second * size);
    }
    
    this->setRangeButtons(rangeButtons);
}

void Game::createCharacterButtons(Field field) {
    std::vector<Button*> characterButtonList;

    for (int i = 0; i < field.getCharacters().size(); i++) {
        characterButtonList.push_back(new Button(field.getCharacters()[i]->getImgString()));
        characterButtonList.back()->setPosition(field.getCharacters()[i]->getPositionX() * 150, field.getCharacters()[i]->getPositionY() * 150);
    }
    
    this->setCharacterButtons(characterButtonList);
}