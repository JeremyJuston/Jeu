#include "Button.hpp"

#include "Window.hpp"

#include <iostream>
using namespace sf;
using namespace std;

Button::Button() {};
Button::~Button() {}

Button::Button(string imgPath) {
	Texture texture;
	if (!texture.loadFromFile(imgPath)) {
		cout << "There was a problem reading the image : " << imgPath << endl;
	}
	m_texture = texture;
	Sprite image(m_texture);
	m_sprite = image;
	Text txt;
	txt.setString("");
	m_text = txt;
};


Button::Button(string msg, string imgPath) {
	Texture texture;
	if (!texture.loadFromFile(imgPath)) {
		cout << "There was a problem reading the image : " << imgPath << endl;
	}
	m_texture = texture;
	Sprite image(m_texture);
	m_sprite = image;
	Text txt;
	txt.setString(msg);
	m_text = txt;
};

sf::Sprite Button::getSprite() {
	return this->m_sprite;
}

bool Button::isInSpriteRect(int x, int y) {
	return this->m_sprite.getGlobalBounds().contains(x, y);
}

void Button::setPosition(int x, int y) {
	m_sprite.setPosition(x, y);
}

sf::Vector2f Button::getPosition() {
	return m_sprite.getPosition();
}