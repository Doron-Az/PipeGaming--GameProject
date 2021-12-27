#include "Sink.h"

Sink::Sink(float width, float height)
{
	m_flow = false;
	m_sprite.setTexture(ResourcesImages::getInstance().getTexture(ResourcesImages::vectorIconType::i_empty_sink));
	m_sprite.setPosition(height, width);
	m_sprite.setOrigin(PIXEL_SIZE/2, PIXEL_SIZE/2);

	m_directions[Direction::d_up] = false;
	m_directions[Direction::d_right] = false;
	m_directions[Direction::d_down] = false;
	m_directions[Direction::d_left] = true;


	sf::Vector2f temp(m_sprite.getPosition().x + PIXEL_SIZE/2, m_sprite.getPosition().y + PIXEL_SIZE/2);
	m_sprite.setPosition(temp);
}
//-----------------------------------------------------------------------------
void Sink::printFlow()
{
	m_flow = true;
	m_sprite.setTexture(ResourcesImages::getInstance().getTexture(ResourcesImages::vectorIconType::i_full_sink));
}
//-----------------------------------------------------------------------------
void Sink::printNoflow()
{
	m_flow = false;
	m_sprite.setTexture(ResourcesImages::getInstance().getTexture(ResourcesImages::vectorIconType::i_empty_sink));

}