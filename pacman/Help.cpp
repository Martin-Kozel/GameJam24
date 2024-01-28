#include "Help.h"
#include "Game.h"

void Help::initialise(sf::Font& t_font)
{
	m_font = t_font;
	m_message.setFont(m_font);
	m_message.setFillColor(sf::Color::White);
	m_message.setCharacterSize(24U);
	m_message.setString("Use arrow keys or WASD to move\n<esc> to return.");

	sf::FloatRect box = m_message.getLocalBounds();
	float posX = (WIDTH - box.width) / 2.0f;
	m_message.setPosition(posX, 150.0f);

}

void Help::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_message);
}

void Help::update(sf::Time t_deltaTime)
{
	if (m_exit)
	{
		Game::s_currentMode = GameMode::Menu;
		m_exit = false;
	}
}

void Help::processEvents(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type)
	{
		if (sf::Keyboard::Escape == t_event.key.code)
		{
			m_exit = true;
		}
	}
}