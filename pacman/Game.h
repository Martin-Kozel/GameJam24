/// <summary>
/// author Martin Kozel and Monika Nusi March 2023
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>

const int WIDTH = 800;
const int HEIGHT = 600;
#include <SFML/Graphics.hpp>
#include "Licence.h"
#include "Splash.h"
#include "Menu.h"
#include "Help.h"
#include "GamePlay.h"



enum class GameMode
{
	None,
	Licence,
	Splash,
	Menu,
	Help,
	GamePlay,
	Pause,
	Garden,
	LivingRoom,
	Bedroom,
	EndScreen
};
class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();
	static GameMode s_currentMode; // current game mode
	static bool m_exitGame; // control exiting game 
private:
	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();

	void setupFontAndText();
	sf::RenderWindow m_window; // main SFML window
	sf::Font m_gameFont; // font used by message
	Licence m_licence;
	Splash m_splash;
	Menu m_menu;
	Help m_help;
	GamePlay m_gameplay;
};

#endif // !GAME_HPP