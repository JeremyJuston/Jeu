#ifndef DEF_BUTTON
#define DEF_BUTTON

#include <SFML/Graphics.hpp>


class Button {
	private :
		sf::Text m_text;
		sf::Sprite m_sprite;
		sf::Texture m_texture;
	public :
		Button();
		~Button();
		Button(std::string imgPath);
		Button(std::string msg, std::string imgPath);
		sf::Sprite getSprite();
		sf::IntRect getSpriteRect();
		bool isInSpriteRect(int x, int y);
		void setPosition(float x, float y);
};

#endif