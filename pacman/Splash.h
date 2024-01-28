#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML/Graphics.hpp>

class Splash
{
public:
	void initialise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window);
	void processEvents(sf::Event t_event);

private:
	sf::Font m_font; // local refrence to game font
	sf::Text m_message; // user prompt
	sf::Text m_message2;
	sf::Texture m_wallPaperTexture; // wallpaper image
	sf::Sprite m_wallPaperSprite; // wallpaperSprite
};

#endif // !SPLASHSCREEN_H