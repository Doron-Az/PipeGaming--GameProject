#pragma once
#include <SFML/Graphics.hpp>
#include "ResourcesImages.h"
#include "Constant.h"
#include <Constant.h>
#include <iostream>
#include <memory>
#include <vector>

class GameObject
{
	
public:
	GameObject() = default;
	virtual ~GameObject() = default;
	sf::Sprite getSprite();
	void rotateDirections(int num);
	void myRotate(int randNum);
	void setLocation(float height, float width);
	void draw(sf::RenderWindow& window);
	bool getDirection(int);
	bool isFlow();


	virtual void printFlow() = 0;
	virtual void printNoflow() = 0;


	enum  Direction
	{
		d_up,
		d_right,
		d_down,
		d_left,
	};
private:
		
protected:
	bool m_directions[NUM_OF_DIRECTIONS] = { 0 };
	bool m_flow;
	sf::Sprite m_sprite;
};