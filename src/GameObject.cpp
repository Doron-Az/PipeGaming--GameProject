#include "GameObject.h"

sf::Sprite GameObject::getSprite()
{
	return m_sprite;
}
//
//-----------------------------------------------------------------------------
void GameObject::setLocation(float height, float width)
{
	m_sprite.setPosition(width, height);
}
//-----------------------------------------------------------------------------
void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
bool GameObject::getDirection(int direction)
{
	return m_directions[direction];
}
bool GameObject::isFlow()
{
	return m_flow;
}
//-----------------------------------------------------------------------------
void GameObject::myRotate(int numOfRotate)
{
	m_sprite.rotate(numOfRotate * ANGEL);
	rotateDirections(numOfRotate);
}
//-------------------------------------------------------------------
//algoritem to move the directions of the object
void GameObject::rotateDirections(int num)
{
	bool tempDirection;

	for (int i = 0; i < num; i++)
	{
		tempDirection = m_directions[3];

		for (int j = 3; j > 0; j--)
		{
			m_directions[j] = 	m_directions[j - 1];
		}
		m_directions[0] = tempDirection;
	}

}
