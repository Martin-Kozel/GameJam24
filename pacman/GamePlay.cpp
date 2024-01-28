#include "GamePlay.h"
#include "Game.h"
#include <iostream>

using namespace std;



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text
/// load and setup thne image
/// </summary>
GamePlay::GamePlay()
{
	setupFontAndText(); // load font
	setupBackground();
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
	checkCollisionsLevel1();


}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void GamePlay::render(sf::RenderWindow& t_window)
{

	t_window.draw(backgroundSprite);
	t_window.draw(m_welcomeMessage);
	t_window.draw(playerSprite);
	t_window.draw(dogSprite);
	t_window.draw(keySprite);
	t_window.draw(doors);
	

}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void GamePlay::setupFontAndText()
{
}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void GamePlay::setupEnemy()
{
	enemy.setFillColor(sf::Color::Red);
	enemy.setPosition(m_location);
	enemy.setSize(enemySize);

	if (!dogTexture.loadFromFile("ASSETS\\IMAGES\\dog.png"))
	{
		std::cout << "Problem loading dog" << "\n";
	}
	dogSprite.setTexture(dogTexture);
	dogSprite.setPosition(m_location);
	dogSprite.setScale(0.5f, 0.5f);
	dogSprite.setOrigin(40.0f, 170.0f);
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
	dogSprite.setPosition(m_location);
}


// Player /////////////////////////////

void GamePlay::checkDirection()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_direction = Direction::Up; // move up
		playerSprite.setOrigin(60.0f, 60.0f);
		movePlayer(); // moves with character
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_direction = Direction::Left; // move left
		playerSprite.setOrigin(60.0f, 60.0f);
		movePlayer(); // moves with character

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_direction = Direction::Down; // move down
		playerSprite.setOrigin(60.0f, 60.0f);
		movePlayer(); // moves with character
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_direction = Direction::Right; // move right
		playerSprite.setOrigin(60.0f, 60.0f);
		movePlayer(); // moves with character
	}
}

// player setup
void GamePlay::setupPlayer() {
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
	playerSprite.setPosition(playerLocation);
	

	// boundry checking player
	if (playerLocation.x <= 25) {
		playerLocation.x = 25;
	}
	if (playerLocation.x >= 1270) {
		playerLocation.x = 1270;
	}
	if (playerLocation.y >= 780) {
		playerLocation.y = 780;
	}
	if (playerLocation.y <= 25) {
		playerLocation.y = 25;
	}
}

void GamePlay::setupMarbles()
{

	marblesLocation = sf::Vector2f{ 120.0f,100.0f };
	marbles.setPosition(marblesLocation);
	marbles.setSize(marblesSize);
	marbles.setFillColor(sf::Color::Yellow);
	marbles.setOrigin(50.0f, 50.0f);

	if (!keyTexture.loadFromFile("ASSETS\\IMAGES\\key.png"))
	{
		std::cout << "Problem loading key" << "\n";
	}
	keySprite.setTexture(keyTexture);
	keySprite.setScale(0.4f, 0.4f);
	keySprite.setPosition(marblesLocation);
	keySprite.setOrigin(150.0f, 200.0f);
}

void GamePlay::setupBackground()
{
	if (!backgroundTexture.loadFromFile("ASSETS\\IMAGES\\garden.png"))
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

void GamePlay::checkCollisionsLevel1() {
	if (player.getGlobalBounds().intersects(marbles.getGlobalBounds())) {
		
		Game::s_currentMode = GameMode::LivingRoom;
		cout << "switched level" << endl;
	}
	
}
