#include "Licence.h"
#include "Game.h"

void Licence::initialise(sf::Font& t_font)
{
	float xPos; // left co ordinate for text
	sf::FloatRect boundingBox; // bounding box for text
	m_font = t_font;
	m_message.setFont(m_font);
	m_message.setString("Handmade by Martin Kozel and Monika Nusi");
	m_message.setFillColor(sf::Color::White);
	m_message.setCharacterSize(24U);
	boundingBox = m_message.getLocalBounds();
	xPos = WIDTH / 2 - boundingBox.width / 2.0f;
	m_message.setPosition(xPos, 200.f);
	m_cumulativeTime = sf::seconds(0.0f);
}
void Licence::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_message);
}
void Licence::update(sf::Time t_deltaTime)
{
	m_cumulativeTime += t_deltaTime;
	if (m_cumulativeTime.asSeconds() > 1.0f)
	{
		Game::s_currentMode = GameMode::Splash;
	}
}