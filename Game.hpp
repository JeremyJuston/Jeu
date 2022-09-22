#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Field.hpp"
#include "Button.hpp"
#include "Input.hpp"


class Game {
	private:
		std::vector<Button*> characterButtons;
		std::vector<Button*> actionButtons;
		std::vector<Button*> rangeButtons;
		Character* activeChar;
		std::string activeAction;

	protected:
		




};




#endif
