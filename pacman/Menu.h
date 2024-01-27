#pragma once


#include <SFML/Graphics.hpp>


const int MENU_OPTIONS = 3;

class Menu
{

public:
	void initialise(sf::Font& t_font);
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void processEvents(sf::Event t_event);

private:
	sf::Texture m_buttonTexture; // texture for button
	sf::Sprite m_buttonSprite; // sprite for all buttons
	sf::Text m_buttonTexts[MENU_OPTIONS]; // text fro buttons
	sf::Vector2f m_buttonLocations[MENU_OPTIONS]; // location of 3 drawings of button sprite
	sf::Font m_font; // refrence to game font

	const float BUTTON_WIDTH = 250.0f;// width of buttons
	const float BUTTON_LEFT = (800 - BUTTON_WIDTH) / 2.0f;// top left of button area
	const float TOP_OFFSET = 150.0f;// top offset to button area
	const float GAP = 50.0f;	// gap between buttons
	const float BUTTON_HEIGHT = 70.0f;// height of button

};