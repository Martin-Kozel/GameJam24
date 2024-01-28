#ifndef ENDSCREEN_HPP
#define ENDSCREEN_HPP

#include <SFML/Graphics.hpp>
class EndScreen
{
public:

	EndScreen();
	~EndScreen();

	void render(sf::RenderWindow& t_window);
	void setupEnd();

private:

	sf::Sprite end;
	sf::Texture endtext;

};
#endif
