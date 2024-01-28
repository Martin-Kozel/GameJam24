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

	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen

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

	void setupBackground();

	void checkCollisionsLevel1();
	

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Texture dogTexture;
	sf::Sprite dogSprite;
	sf::Texture keyTexture;
	sf::Sprite keySprite;


	// AI Variables
	sf::RectangleShape enemy;
	sf::Vector2f enemySize = { 130.0f, 100.0f };

	sf::Vector2f m_targets[MAX_TARGETS] = { {101.0f, 600.0f}, {600.0f, 50.0f}, {50.0f, 50.0f}, {100.0f, 150.0f} }; // Targets
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
	sf::Vector2f playerSize = { 130.0f, 220.0f };


	// marbles
	sf::RectangleShape marbles;
	sf::Vector2f marblesLocation;
	sf::Vector2f marblesSize = { 120.0f, 70.0f };


	sf::RectangleShape doors;
	sf::Vector2f doorLocation;
	sf::Vector2f doorSize{ 60.0f,220.0f };

	bool takeMarbles = false;
	
	sf::Text gameovertext;
	int level = 1;


};

#endif // !GAME_HPP