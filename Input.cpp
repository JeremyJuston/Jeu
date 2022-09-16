#include "Input.hpp"
#include <iostream>
using namespace std;
Input::Input() {
	action.left_click = action.right_click = action.escape = false;
	action.mouse_position = sf::Vector2<int>::Vector2();
}


Input::Action Input::getAction() {
	return this->action;
}

void Input::setActions(bool state) {
	action.left_click = action.right_click = action.escape = false;
}

//Handle all types of events triggered on the game Window
void Input::eventHandler(Event event, RenderWindow& window) {

    if (event.type == Event::Closed) {
        window.close();
    }

	if (event.type == Event::KeyPressed) {
		switch (event.key.code)
		{
		case Keyboard::Escape:
			action.escape = true;
			break;
		}
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		switch (event.mouseButton.button)
		{
		case Mouse::Left:
			action.mouse_position = Mouse::getPosition(window);
			action.left_click = true;
			break;
		}
		
	}
}