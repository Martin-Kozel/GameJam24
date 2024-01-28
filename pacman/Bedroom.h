#ifndef BEDROOM_HPP
#define BEDROOM_HPP

#include <SFML/Graphics.hpp>

enum class Direction3
{
	None,
	Right,
	Up,
	Down,
	Left
};

class BedRoom
{

public:

	BedRoom();
	~BedRoom();
	void setFont(sf::Font t_font) { m_ArialBlackfont = t_font; }

	void processEvents(sf::Event t_event);
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);

private:

	// Text
	void setupFontAndText();

	// Player functions
	void checkDirection();
	void setupPlayer();
	void movePlayer();

	// Bed Functions
	void setupBed();

	// Marker Functions
	void setupMarker();

	// Collisions
	void checkCollisions();
	void setupBackground();

	// player setup
	sf::RectangleShape player;
	sf::Vector2f playerLocation;
	sf::Vector2f playerSpeed;
	float m_speed1{ 4.00f };
	Direction3 m_direction{ Direction3::None };
	sf::Vector2f playerSize = { 130.0f, 220.0f };

	// Text
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen

	// NPC / Bed
	sf::RectangleShape bed;
	sf::Vector2f bedLocation = { 1150.0f, 200.0f };
	sf::Vector2f bedSize = { 100.0f, 200.0f };

	// Marker
	sf::RectangleShape marker;
	sf::Vector2f markerLocation = { 850.0f, 200.0f };
	sf::Vector2f markerSize = { 10.0f, 20.0f };
	bool markerGot = false;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Texture markerTexture;
	sf::Sprite markerSprite; 
	sf::Texture bedTexture;
	sf::Sprite bedSprite;
};
#endif