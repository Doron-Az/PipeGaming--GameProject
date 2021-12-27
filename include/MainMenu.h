#pragma once
#include <SFML/Graphics.hpp>
#include "ResourcesImages.h"

#include "Constant.h"

class MainMenu
{
public:
	enum buttonType
	{
		e_play,
		e_exit,
		e_nothing
	};

	MainMenu();
	void run();
	void draw();
	int clickOnMenu(sf::Vector2f clickLocation);

private:
	int m_width;
	int m_height;

	bool m_isFrame = false;

	sf::Vector2f m_locationMouse;
	sf::Sprite m_sprite;
	sf::RenderWindow m_window;
	sf::RectangleShape m_frame;
};