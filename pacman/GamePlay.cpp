/// <summary>
/// @author Peter Lowe
/// @date May 2019
///
/// you need to change the above lines or lose marks
/// </summary>

#include "GamePlay.h"
#include <iostream>



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text
/// load and setup thne image
/// </summary>
GamePlay::GamePlay()
{
	setupFontAndText(); // load font
	setupEnemy(); // load texture
	setupPlayer(); // load player
	setupMarbles(); // load marbles
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
GamePlay::~GamePlay()
{
}


void GamePlay::processEvents(sf::Event t_event)
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
void GamePlay::processKeys(sf::Event t_event)
{
	
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void GamePlay::update(sf::Time t_deltaTime)
{
	

	aiTargeting();
	aiMove();
	checkDirection();

}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void GamePlay::render(sf::RenderWindow& t_window)
{

	t_window.draw(m_welcomeMessage);
	t_window.draw(enemy);
	t_window.draw(player);
	t_window.draw(marbles);
	

}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void GamePlay::setupFontAndText()
{
	
	m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("Get Pranked, Neighbor");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(500.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(45U);
	m_welcomeMessage.setOutlineColor(sf::Color::Red);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);

}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void GamePlay::setupEnemy()
{
	enemy.setFillColor(sf::Color::Red);
	enemy.setPosition(m_location);
	enemy.setSize(enemySize);
}


void GamePlay::aiTargeting()
{
	// Variables
	float lenght = 0.0f;
	sf::Vector2f heading(0.0f, 0.0f);

	heading.x = (m_targets[m_currentPoint].x) - m_location.x;
	heading.y = (m_targets[m_currentPoint].y) - m_location.y;
	lenght = sqrtf((heading.x * heading.x) + (heading.y * heading.y)); // find the distance

	heading = heading / lenght;
	heading = heading * m_speed; // change speed to the actual speed
	m_velocity = heading;


	if (static_cast<float>(m_targets[m_currentPoint].x) > m_location.x)
	{
		m_facing = Direction::Right;
	}
	else
	{
		m_facing = Direction::Left;

	}
}



void GamePlay::aiMove()
{

	if (m_facing != Direction::None)
	{
		m_location += m_velocity;
		enemy.setPosition(m_location);

		if (m_facing == Direction::Right && m_location.x >= m_targets[m_currentPoint].x)
		{
			m_facing = Direction::None;

			// Change target
			if (m_currentPoint >= MAX_TARGETS - 1)
			{
				m_currentPoint = 0;
			}
			else
			{
				m_currentPoint++;
			}
		}


		if (m_facing == Direction::Left && m_location.x <= m_targets[m_currentPoint].x)
		{
			m_facing = Direction::None;

			// Change target
			if (m_currentPoint >= MAX_TARGETS)
			{
				m_currentPoint++;
			}
			else
			{
				m_currentPoint = 0;
			}
		}
	}

}





// Player /////////////////////////////

void GamePlay::checkDirection()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_direction = Direction::Up; // move up
		movePlayer(); // moves with character
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_direction = Direction::Left; // move left
		movePlayer(); // moves with character

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_direction = Direction::Down; // move down
		movePlayer(); // moves with character
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_direction = Direction::Right; // move right
		movePlayer(); // moves with character
	}
}

// player setup
void GamePlay::setupPlayer() {
	player.setPosition(475.0f, 400.0f);
	playerLocation = sf::Vector2f{ 475.0f,400.0f };
	player.setSize(playerSize);
	player.setFillColor(sf::Color::Cyan);
	player.setOrigin(20.0f, 20.0f);
}

void GamePlay::movePlayer() {
	sf::Vector2f movement{ 0.0f,0.0f };

	switch (m_direction) {
	case Direction::Up:
		movement.y = -m_speed; // player go up
		break;
	case Direction::Down:
		movement.y = m_speed; // player go down
		break;
	case Direction::Left:
		movement.x = -m_speed; // player go left
		break;
	case Direction::Right:
		movement.x = m_speed; // player go right
		break;
	default:
		break;
	}

	playerLocation += movement;
	player.setPosition(playerLocation);

	// boundry checking player
	if (playerLocation.x <= 25) {
		playerLocation.x = 25;
	}
	if (playerLocation.x >= 740) {
		playerLocation.x = 740;
	}
	if (playerLocation.y >= 540) {
		playerLocation.y = 540;
	}
	if (playerLocation.y <= 25) {
		playerLocation.y = 25;
	}
}

void GamePlay::setupMarbles()
{

	marblesLocation = sf::Vector2f{ 50.0f,50.0f };
	marbles.setPosition(marblesLocation);
	marbles.setSize(marblesSize);
	marbles.setFillColor(sf::Color::Yellow);
	marbles.setOrigin(20.0f, 20.0f);
}