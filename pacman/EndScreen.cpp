#include "EndScreen.h"

EndScreen::EndScreen()
{
	setupEnd();
}

EndScreen::~EndScreen()
{
}



void EndScreen::render(sf::RenderWindow& t_window)
{
	t_window.draw(end);
}

void EndScreen::setupEnd()
{
	if (!endtext.loadFromFile("ASSETS\\IMAGES\\endscreen.png"))
	{
		
	}
	end.setTexture(endtext);
	end.setScale(10.0f, 10.0f);
}


