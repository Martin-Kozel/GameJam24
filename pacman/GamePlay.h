/// <summary>
/// author Ian Perez Bunuel 2024
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>

// Constants
const int MAX_TARGETS = 4;

enum class Direction
{
	None,
	Right,
	Up,
	Down,
	Left
};

enum class enemyDirection
{
	None,
	Right,
	Left
};

class GamePlay
{

public:

	GamePlay();
	~GamePlay();
	void setFont(sf::Font t_font) { m_ArialBlackfont = t_font; }

	void processEvents(sf::Event t_event);
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);

private:

	void setupFontAndText();
	void setupEnemy();

	// AI functions
	void aiMove();
	void aiTargeting();

	// Player functions
	void checkDirection();
	void setupPlayer();
	void movePlayer();

	// Item functions
	void setupMarbles();

	// Collision


	
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen

	// AI Variables
	sf::RectangleShape enemy;
	sf::Vector2f enemySize = { 50.0f, 50.0f };

	sf::Vector2f m_targets[MAX_TARGETS] = { {101.0f, 250.0f}, {200.0f, 250.0f}, {100.0f, 150.0f}, {100.0f, 150.0f} }; // Targets
	sf::Vector2f m_location = { 50.0f, 50.0f };
	Direction m_facing = Direction::None; // Direction facing

	float m_aiSpeed = 5.0f;
	sf::Vector2f m_velocity = { 0.0f, 0.0f };
	int m_currentPoint = 0;
	bool m_firstCycle = true;


	// player setup
	sf::RectangleShape player;
	sf::Vector2f playerLocation;
	sf::Vector2f playerSpeed;
	float m_speed{ 4.00f };
	Direction m_direction{ Direction::None };
	sf::Vector2f playerSize = { 40.0f, 80.0f };


	// marbles
	sf::RectangleShape marbles;
	sf::Vector2f marblesLocation;
	sf::Vector2f marblesSize = { 35.0f, 35.0f };

	bool takeMarbles = false;

	// Views


};

#endif // !GAME_HPP