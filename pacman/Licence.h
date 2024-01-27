#pragma once
#include <SFML/Graphics.hpp>
class Licence
{
public:
	void initialise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);

private:
	sf::Font m_font; // local refrence to font from game class
	sf::Text m_message; // licence text
	sf::Time m_cumulativeTime;// timer to count to one second
};