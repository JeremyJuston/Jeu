#ifndef DEF_INPUT
#define DEF_INPUT
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

class Input {
	
	struct Action {
		bool right_click, left_click, escape;
		sf::Vector2i mouse_position;
	};

public:
	Input();
	Action getAction();
	void setActions(bool state);
	void eventHandler(sf::Event event, sf::RenderWindow& window);


private:
	Action action;


};


#endif