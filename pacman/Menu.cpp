#include "Menu.h"

#include <iostream>

#include "game.h"


void Menu::initialise(sf::Font& t_font)
{
	m_font = t_font;
	int textDropOffset = 23.0f;
	std::string menuTexts[] = { "Play" , "Help", "Quit" };
	sf::Vector2u textureSize;
	if (!m_buttonTexture.loadFromFile("ASSETS\\IMAGES\\button.png"))
	{
		std::cout << "problenm with button" << std::endl;
	}
	m_buttonSprite.setTexture(m_buttonTexture);
	textureSize = m_buttonTexture.getSize();
	float scaleX = BUTTON_WIDTH / textureSize.x;
	float scaleY = BUTTON_HEIGHT / textureSize.y;
	m_buttonSprite.setScale(scaleX, scaleY);
	for (int i = 0; i < MENU_OPTIONS; i++)
	{
		m_buttonLocations[i] = sf::Vector2f{ BUTTON_LEFT, TOP_OFFSET + (GAP + BUTTON_HEIGHT) * i };
		m_buttonTexts[i].setFont(m_font);
		m_buttonTexts[i].setFillColor(sf::Color::Black);
		m_buttonTexts[i].setCharacterSize(24U);
		m_buttonTexts[i].setString(menuTexts[i]);
		sf::FloatRect box = m_buttonTexts[i].getLocalBounds();
		float offset = (BUTTON_WIDTH - box.width) / 2.0f;
		m_buttonTexts[i].setPosition(BUTTON_LEFT + offset, TOP_OFFSET + textDropOffset + (GAP + BUTTON_HEIGHT) * i);

	}

}

void Menu::update(sf::Time t_deltaTime)
{
}

void Menu::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < MENU_OPTIONS; i++)
	{
		m_buttonSprite.setPosition(m_buttonLocations[i]);
		t_window.draw(m_buttonSprite);
		t_window.draw(m_buttonTexts[i]);
	}
}

void Menu::processEvents(sf::Event t_event)
{
	sf::Vector2i mouse;
	if (sf::Event::MouseButtonReleased == t_event.type)
	{
		mouse.x = t_event.mouseButton.x;
		mouse.y = t_event.mouseButton.y;
		if (mouse.x > BUTTON_LEFT && mouse.x < BUTTON_LEFT + BUTTON_WIDTH)
		{
			if (mouse.y > TOP_OFFSET && mouse.y < TOP_OFFSET + BUTTON_HEIGHT)
			{
				Game::s_currentMode = GameMode::GamePlay;
			}
			if (mouse.y > (TOP_OFFSET + GAP + BUTTON_HEIGHT) &&
				mouse.y < TOP_OFFSET + GAP + BUTTON_HEIGHT * 2)
			{
				Game::s_currentMode = GameMode::Help;
			}
			if (mouse.y > TOP_OFFSET + GAP * 2 + BUTTON_HEIGHT * 2 &&
				mouse.y < TOP_OFFSET + GAP * 2 + BUTTON_HEIGHT * 3)
			{
				Game::m_exitGame = true;
			}
		}

	}
}