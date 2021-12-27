#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Information
{
public:

	Information() = default;
	Information(int score, int clicks, int level, float height, float width);

	void setInformation(int score, int live,int level);
	void setText(sf::Text&, const sf::Color&, std::string, float, float);
	void setPosition(float height);
	void draw(sf::RenderWindow& window);

private:

	unsigned int m_score;
	unsigned int m_clickNum;
	unsigned int m_level;
	float m_width;
	float m_height;

	sf::Font m_font;
	sf::Text m_text[6];
};