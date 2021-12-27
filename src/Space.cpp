#include "Space.h"

Space::Space(float height, float width)
{
	m_flow = false;

	m_sprite.setTexture(ResourcesImages::getInstance().getTexture(ResourcesImages::vectorIconType::i_empty));
	m_sprite.setPosition(width, height);
	m_sprite.setOrigin(PIXEL_SIZE/ 2, PIXEL_SIZE /2);

	m_directions[Direction::d_up] = false;
	m_directions[Direction::d_right] = false;
	m_directions[Direction::d_down] = false;
	m_directions[Direction::d_left] = false;

	sf::Vector2f temp(m_sprite.getPosition().x + PIXEL_SIZE /2, m_sprite.getPosition().y + PIXEL_SIZE/2);
	m_sprite.setPosition(temp);
}

//-----------------------------------------------------------------------------
void Space::printFlow(){}
//-----------------------------------------------------------------------------
void Space::printNoflow(){}
