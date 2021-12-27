#include "Information.h"

//-----------------------------------------------------------------------------
Information::Information(int score, int clicks, int level, float height, float width):
	m_score(score), m_clickNum(clicks), m_level(level), m_height(height), m_width(width)
{
	
	if (!m_font.loadFromFile("FontFile.ttf"))
	{
		std::cout << "Error font" << std::endl;
		exit(EXIT_FAILURE);
	}

	setText(m_text[0], sf::Color::Black, "Score ", height, 0);
	setText(m_text[1], sf::Color::Red, std::to_string(score), height, 125);
	setText(m_text[2], sf::Color::Black, "Clicks ", height, 225);
	setText(m_text[3], sf::Color::Red, std::to_string(clicks), height, 350);
	setText(m_text[4], sf::Color::Black, "Level ", height, 425);
	setText(m_text[5], sf::Color::Red, std::to_string(level), height, 550);
}
//-----------------------------------------------------------------------------
void Information::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 6; i++)
		window.draw(m_text[i]);
}
//-----------------------------------------------------------------------------
void Information::setPosition(float height)
{
	for (int i = 0; i < 6; i++) {
		m_text[i].setPosition(m_text[i].getPosition().x, height + 10);
	}
}
//-----------------------------------------------------------------------------
void Information::setInformation(int score, int clicks, int level)
{
	m_text[1].setString(std::to_string(score));
	m_text[3].setString(std::to_string(clicks));
	m_text[5].setString(std::to_string(level));
}
//-----------------------------------------------------------------------------
void Information::setText(sf::Text& text, const sf::Color& color, std::string str,
	float height, float width)
{
	text.setString(str);
	text.setPosition(width, height);
	text.setFont(m_font);
	text.setFillColor(color);
}
//-----------------------------------------------------------------------------
