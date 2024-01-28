#include "Game.h"
#include "GamePlay.h"
#include <iostream>

GameMode Game::s_currentMode = GameMode::Licence;
bool Game::m_exitGame{ false }; // when true exit game


Game::Game() :
	m_window{ sf::VideoMode{ 1400U, 1000U, 32U }, "SFML Game" }
{
	setupFontAndText(); // load font 
	m_licence.initialise(m_gameFont);
	m_splash.initialise(m_gameFont);
	m_menu.initialise(m_gameFont);
	m_help.initialise(m_gameFont);
	m_gameplay.setFont(m_gameFont);
	m_livingroom.setFont(m_gameFont);
	m_bedroom.setFont(m_gameFont);
	
}


Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		switch (s_currentMode)
		{
		case GameMode::None:
			break;
		case GameMode::Licence:
			break;
		case GameMode::Splash:
			m_splash.processEvents(newEvent);
			break;
		case GameMode::Menu:
			m_menu.processEvents(newEvent);
			break;
		case GameMode::Help:
			m_help.processEvents(newEvent);
			break;
		case GameMode::GamePlay:
			m_gameplay.processEvents(newEvent);
			break;
		case GameMode::Pause:
			break;
		case GameMode::LivingRoom:
			m_livingroom.processEvents(newEvent);
			break;
		case GameMode::Bedroom:
			m_bedroom.processEvents(newEvent);
			break;
		case GameMode::EndScreen:
			
			break;
		default:
			break;
		}
	}
}

void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	switch (s_currentMode)
	{
	case GameMode::None:
		break;
	case GameMode::Licence:
		m_licence.update(t_deltaTime);
		break;
	case GameMode::Splash:
		break;
	case GameMode::Menu:
		break;
	case GameMode::Help:
		m_help.update(t_deltaTime);
		break;
	case GameMode::GamePlay:
		m_gameplay.update(t_deltaTime);
		break;
	case GameMode::Pause:
		break;
	case GameMode::LivingRoom:
		m_livingroom.update(t_deltaTime);
		break;
	case GameMode::Bedroom:
		m_bedroom.update(t_deltaTime);
		break;
	case GameMode::EndScreen:
		break;
	default:
		break;
	}
}

void Game::render()
{
	m_window.clear(sf::Color::Black);
	switch (s_currentMode)
	{
	case GameMode::None:
		break;
	case GameMode::Licence:
		m_licence.render(m_window);
		break;
	case GameMode::Splash:
		m_splash.render(m_window);
		break;
	case GameMode::Menu:
		m_menu.render(m_window);
		break;
	case GameMode::Help:
		m_help.render(m_window);
		break;
	case GameMode::GamePlay:
		m_gameplay.render(m_window);
		break;
	case GameMode::Pause:
		break;
	case GameMode::LivingRoom:
		m_livingroom.render(m_window);
		break;
	case GameMode::Bedroom:
		m_bedroom.render(m_window);
		break;
	case GameMode::EndScreen:
		m_endscreen.render(m_window);
		break;
	default:
		break;
	}
	m_window.display();
}

void Game::setupFontAndText()
{
	if (!m_gameFont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
}