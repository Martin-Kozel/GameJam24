#ifndef LivingRoom_HPP
#define LivingRoom_HPP

#include <SFML/Graphics.hpp>


enum class Direction2
{
	None,
	Right,
	Up,
	Down,
	Left
};


class LivingRoom
{

public:

	LivingRoom();
	~LivingRoom();
	void setFont(sf::Font t_font) { m_ArialBlackfont = t_font; }

	void processEvents(sf::Event t_event);
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);

private:

	void setupFontAndText();

	// Player functions
	void checkDirection();
	void setupPlayer();
	void movePlayer();

	// Laser Functions
	void setupLaser();
	void setupLever();

	void checkCollisions();
	void setupBackground();

	// player setup
	sf::RectangleShape player;
	sf::Vector2f playerLocation;
	sf::Vector2f playerSpeed;
	float m_speed1{ 4.00f };
	Direction2 m_direction{ Direction2::None };
	sf::Vector2f playerSize = { 130.0f, 220.0f };

	// Text
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen

	// Laser
	sf::RectangleShape laser;
	sf::Vector2f laserSize = { 4.0f, 900.0f };
	sf::Vector2f laserLocation = { 1350.0f, 40.0f };
	bool laserOn = true;
	// Lever
	sf::RectangleShape lever;
	sf::Vector2f leverSize = { 20.0f, 40.0f };
	sf::Vector2f leverLocation = { 1200.0f, 50.0f };

	sf::RectangleShape doors;
	sf::Vector2f doorLocation;
	sf::Vector2f doorSize{ 20.0f,220.0f };

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

};

#endif