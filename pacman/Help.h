#pragma once
#include <SFML/Graphics.hpp>
class Help
{
public:
	void initialise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);
	void processEvents(sf::Event t_event);

private:
	sf::Font m_font; // game font
	sf::Text m_message; // help text
	bool m_exit{ false };
};
