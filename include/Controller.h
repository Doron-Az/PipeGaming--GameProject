#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <iostream>

#include "Board.h"
#include "ResourcesImages.h"
#include "ResourcesSounds.h"
#include "Constant.h"
#include "MainMenu.h"
#include "Information.h"

class Controller
{
public:

	Controller();
	void run();
	void nextLevel(sf::RenderWindow& window);
	void openWindowNextLevel(sf::RenderWindow& window);
	void endOfTheGame(sf::RenderWindow& window);
	void checkIfLevelCompleted(sf::RenderWindow& window);
	sf::RectangleShape printOutLine();

private:
	int m_height, m_width;
	int m_heightWindow, m_widthWindow;
	int m_numOfClicks;
	int m_score;
	bool m_isCompleted;

	Board m_board;
	sf::Sprite m_background;
	sf::Vector2f m_locationMove;
	sf::Vector2f m_locationClick;
	Information m_information;
};