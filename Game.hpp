#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Field.hpp"
#include "Button.hpp"
#include "Input.hpp"


class Game {
	private:
		std::vector<Button*> m_characterButtons;
		std::vector<Button*> m_actionButtons;
		std::vector<Button*> m_rangeButtons;
		Character* m_activeChar;
		std::string m_activeAction;

	public:
		Game();
		~Game();
		std::vector<Button*> getCharacterButtons();
		std::vector<Button*> getActionButtons();
		std::vector<Button*> getRangeButtons();
		Character* getActiveChar();
		std::string getActiveAction();

		void setCharacterButtons(std::vector<Button*> charButtons);
		void setActionButtons(std::vector<Button*> actionButtons);
		void setRangeButtons(std::vector<Button*> rangeButtons);
		void setActiveChar(Character* actChar);
		void setActiveAction(std::string actAction);

		void checkAction(Field &field, Input input, RenderWindow &window);
		int retrieveCharIndex(Field field);
		void createActions(Button* charButton);
		void clearDisplay();
		void actionClicked(Field field, int act_index);
		void characterClicked(Field field, int char_index);
		void rangeClicked(Field &field, int range_index);
		void createRangeList(Field field);
		void createCharacterList(Field field);


};




#endif
