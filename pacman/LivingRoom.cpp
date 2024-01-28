#include "LivingRoom.h"
#include <iostream>
#include "game.h"


LivingRoom::LivingRoom()
{
	setupFontAndText(); // load font
	setupPlayer();
	setupLaser();
	setupLever();
	setupBackground();
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
LivingRoom::~LivingRoom()
{
}


void LivingRoom::processEvents(sf::Event t_event)
{


	if (sf::Event::KeyPressed == t_event.type) //user pressed a key
	{
		processKeys(t_event);
	}

}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void LivingRoom::processKeys(sf::Event t_event)
{

}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void LivingRoom::update(sf::Time t_deltaTime)
{
	checkDirection();
	checkCollisions();
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void LivingRoom::render(sf::RenderWindow& t_window)
{
	t_window.draw(backgroundSprite);
	t_window.draw(m_welcomeMessage);
	t_window.draw(laser);
	t_window.draw(lever);
	t_window.draw(doors);
	t_window.draw(playerSprite);
	

}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void LivingRoom::setupFontAndText()
{

	m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("LivingRoom");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(500.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(45U);
	m_welcomeMessage.setOutlineColor(sf::Color::Red);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);

}


// Player
void LivingRoom::checkDirection()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_direction = Direction2::Up; // move up
		playerSprite.setOrigin(60.0f, 60.0f);
		movePlayer(); // moves with character
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_direction = Direction2::Left; // move left
		playerSprite.setOrigin(60.0f, 60.0f);
		movePlayer(); // moves with character

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_direction = Direction2::Down; // move down
		playerSprite.setOrigin(60.0f, 60.0f);
		movePlayer(); // moves with character
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_direction = Direction2::Right; // move right
		playerSprite.setOrigin(60.0f, 60.0f);
		movePlayer(); // moves with character
	}
}

// player setup
void LivingRoom::setupPlayer()
{
	player.setPosition(475.0f, 780.0f);
	playerLocation = sf::Vector2f{ 475.0f,780.0f };
	player.setSize(playerSize);
	player.setFillColor(sf::Color::Cyan);


	if (!playerTexture.loadFromFile("ASSETS\\IMAGES\\player.png"))
	{
		std::cout << "Problem loading player" << "\n";
	}
	playerSprite.setTexture(playerTexture);
	playerSprite.setScale(0.4f, 0.4f);
	playerSprite.setPosition(playerLocation);
	playerSprite.setOrigin(60.0f, 60.0f);
}

void LivingRoom::movePlayer()
{
	sf::Vector2f movement{ 0.0f,0.0f };

	switch (m_direction) {
	case Direction2::Up:
		movement.y = -m_speed1; // player go up
		break;
	case Direction2::Down:
		movement.y = m_speed1; // player go down
		break;
	case Direction2::Left:
		movement.x = -m_speed1; // player go left
		break;
	case Direction2::Right:
		movement.x = m_speed1; // player go right
		break;
	default:
		break;
	}

	playerLocation += movement;
	player.setPosition(playerLocation);
	playerSprite.setPosition(playerLocation);

	// boundry checking player
	if (playerLocation.x <= 25) {
		playerLocation.x = 25;
	}
	if (playerLocation.x >= 1340) {
		playerLocation.x = 1340;
	}
	if (playerLocation.y >= 940) {
		playerLocation.y = 940;
	}
	if (playerLocation.y <= 25) {
		playerLocation.y = 25;
	}
}

// Laser
// laser setup
void LivingRoom::setupLaser()
{
	laser.setPosition(laserLocation);
	laser.setSize(laserSize);
	laser.setFillColor(sf::Color::Red);
}
// lever setup
void LivingRoom::setupLever()
{
	lever.setPosition(leverLocation);
	lever.setSize(leverSize);
	lever.setFillColor(sf::Color::White);

	
}


// Collision
void LivingRoom::checkCollisions()
{
	// if the player collides with the lever
	if (player.getGlobalBounds().intersects(lever.getGlobalBounds()))
	{
		laserOn = false;
		for (laserSize.y; laserSize.y != 0 && laserOn == false; laserSize.y--)
		{
			laser.setSize(laserSize);
		}
	}

	if (player.getGlobalBounds().intersects(laser.getGlobalBounds()) && laserOn == true)
	{
		std::cout << "Game Over" << std::endl;
	}

	if (player.getGlobalBounds().intersects(doors.getGlobalBounds())) {
		Game::s_currentMode = GameMode::Bedroom;
		std::cout << "switched level" << std::endl;
	}
}

void LivingRoom::setupBackground() {
	if (!backgroundTexture.loadFromFile("ASSETS\\IMAGES\\livingroom.png"))
	{
		std::cout << "Problem loading background" << "\n";
	}
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(10.0f, 10.0f);

	doors.setPosition(1350.0f, 400.0f);
	doorLocation = sf::Vector2f{ 475.0f,400.0f };
	doors.setSize(doorSize);
	doors.setFillColor(sf::Color::White);
}