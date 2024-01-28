#include "Splash.h"
#include "Game.h"

#include <iostream>

void Splash::initialise(sf::Font& t_font)
{
	float xPos; // left coord of centered text
	sf::FloatRect boundingBox; // bounding box of text

	if (!m_wallPaperTexture.loadFromFile("ASSETS\\IMAGES\\splash.png"))
	{
		std::cout << "problem with wall paper" << std::endl;
	}
	m_wallPaperTexture.setRepeated(true);
	m_wallPaperSprite.setTexture(m_wallPaperTexture);
	m_wallPaperSprite.setTextureRect(sf::IntRect(0, 0, WIDTH, HEIGHT));
	m_wallPaperSprite.setScale(10.0f, 10.0f);
	m_font = t_font;
	m_message.setFont(m_font);
	m_message.setString("Press any key to continue");
	m_message.setFillColor(sf::Color::White);
	m_message.setOutlineColor(sf::Color::Black);
	m_message.setOutlineThickness(1.0f);
	m_message.setCharacterSize(24U);

	m_message2.setFont(m_font);
	m_message2.setString("Get Pranked, Neighbor");
	m_message2.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_message2.setPosition(400.0f, 40.0f);
	m_message2.setCharacterSize(45U);
	m_message2.setOutlineColor(sf::Color::Red);
	m_message2.setFillColor(sf::Color::Black);
	m_message2.setOutlineThickness(3.0f);

	boundingBox = m_message.getLocalBounds();
	xPos = WIDTH / 2 - boundingBox.width / 2.0f;
	m_message.setPosition(xPos*2.2, 800.0f);

}

void Splash::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_wallPaperSprite);
	t_window.draw(m_message);
	t_window.draw(m_message2);
}


void Splash::processEvents(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type
		|| sf::Event::MouseButtonPressed == t_event.type)
	{
		Game::s_currentMode = GameMode::Menu;
	}
}