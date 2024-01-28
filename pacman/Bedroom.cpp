#include "BedRoom.h"
#include <iostream>
#include "game.h"


BedRoom::BedRoom()
{
	setupFontAndText(); // load font
	setupBed();
	setupMarker();
	setupPlayer();
	setupBackground();
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
BedRoom::~BedRoom()
{
}


void BedRoom::processEvents(sf::Event t_event)
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
void BedRoom::processKeys(sf::Event t_event)
{

}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void BedRoom::update(sf::Time t_deltaTime)
{
	checkDirection();
	checkCollisions();
	
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void BedRoom::render(sf::RenderWindow& t_window)
{
	t_window.draw(backgroundSprite);
	t_window.draw(m_welcomeMessage);
	t_window.draw(bed);
	t_window.draw(marker);
	t_window.draw(playerSprite);
	t_window.draw(bedSprite);
	

}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void BedRoom::setupFontAndText()
{

	m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("BedRoom");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(500.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(45U);
	m_welcomeMessage.setOutlineColor(sf::Color::Red);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);

}


// Player
void BedRoom::checkDirection()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_direction = Direction3::Up; // move up
		playerSprite.setOrigin(60.0f, 60.0f);
		movePlayer(); // moves with character
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_direction = Direction3::Left; // move left
		playerSprite.setOrigin(60.0f, 60.0f);
		movePlayer(); // moves with character

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_direction = Direction3::Down; // move down#
		playerSprite.setOrigin(60.0f, 60.0f);
		movePlayer(); // moves with character
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_direction = Direction3::Right; // move right
		playerSprite.setOrigin(60.0f, 60.0f);
		movePlayer(); // moves with character
	}
}

// player setup
void BedRoom::setupPlayer()
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

void BedRoom::movePlayer()
{
	sf::Vector2f movement{ 0.0f,0.0f };

	switch (m_direction) {
	case Direction3::Up:
		movement.y = -m_speed1; // player go up
		break;
	case Direction3::Down:
		movement.y = m_speed1; // player go down
		break;
	case Direction3::Left:
		movement.x = -m_speed1; // player go left
		break;
	case Direction3::Right:
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

void BedRoom::setupBed()
{
	bed.setPosition(bedLocation);
	bed.setSize(bedSize);
	bed.setFillColor(sf::Color::Red);

	if (!playerTexture.loadFromFile("ASSETS\\IMAGES\\bed.png"))
	{
		std::cout << "Problem loading player" << "\n";
	}
	bedSprite.setTexture(bedTexture);
	bedSprite.setScale(0.4f, 0.4f);
	bedSprite.setPosition(bedLocation);
	bedSprite.setOrigin(150.0f, 200.0f);
}

void BedRoom::setupMarker()
{
	marker.setPosition(markerLocation);
	marker.setSize(markerSize);
	marker.setFillColor(sf::Color::Green);
}


void BedRoom::checkCollisions()
{
	if (player.getGlobalBounds().intersects(bed.getGlobalBounds()))
	{


		if (markerGot)
		{
			Game::s_currentMode = GameMode::EndScreen;
			std::cout << "You win";
		}
		else
		{
			std::cout << "Game over";
		}
	}

	if (player.getGlobalBounds().intersects(marker.getGlobalBounds()))
	{
		markerGot = true;
		marker.setFillColor(sf::Color::Transparent);
	}
}

void BedRoom::setupBackground()
{
	if (!backgroundTexture.loadFromFile("ASSETS\\IMAGES\\bedroom.png"))
	{
		std::cout << "Problem loading background" << "\n";
	}
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(10.0f, 10.0f);
}



