#include "Splash.h"
#include "Game.h"
#include <iostream>

void Splash::initialise(sf::Font& t_font)
{
	float xPos; // left coord of centered text
	sf::FloatRect boundingBox; // bounding box of text

	if (!m_wallPaperTexture.loadFromFile("ASSETS\\IMAGES\\splash.jpg"))
	{
		std::cout << "problem with wall paper" << std::endl;
	}
	m_wallPaperTexture.setRepeated(true);
	m_wallPaperSprite.setTexture(m_wallPaperTexture);
	m_wallPaperSprite.setTextureRect(sf::IntRect(0, 0, WIDTH, HEIGHT));
	m_font = t_font;
	m_message.setFont(m_font);
	m_message.setString("Press any key to continue");
	m_message.setFillColor(sf::Color::Yellow);
	m_message.setOutlineColor(sf::Color::Black);
	m_message.setOutlineThickness(1.0f);
	m_message.setCharacterSize(24U);

	boundingBox = m_message.getLocalBounds();
	xPos = WIDTH / 2 - boundingBox.width / 2.0f;
	m_message.setPosition(xPos, 400.0f);

}

void Splash::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_wallPaperSprite);
	t_window.draw(m_message);
}


void Splash::processEvents(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type
		|| sf::Event::MouseButtonPressed == t_event.type)
	{
		Game::s_currentMode = GameMode::Menu;
	}
}