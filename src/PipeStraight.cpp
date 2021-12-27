#include "PipeStraight.h"

PipeStraight::PipeStraight(float width, float height, int rand)
{
	m_flow = false;

	m_sprite.setTexture(ResourcesImages::getInstance().getTexture(ResourcesImages::vectorIconType::i_empty_pipe2));
	m_sprite.setPosition(height, width);
	m_sprite.setOrigin(PIXEL_SIZE/2, PIXEL_SIZE/2);
	m_directions[Direction::d_up] = true;
	m_directions[Direction::d_right] = false;
	m_directions[Direction::d_down] = true;
	m_directions[Direction::d_left] = false;

	myRotate(rand);

	sf::Vector2f temp(m_sprite.getPosition().x + PIXEL_SIZE/2, m_sprite.getPosition().y + PIXEL_SIZE/2);
	m_sprite.setPosition(temp);


}
//-----------------------------------------------------------------------------
void PipeStraight::printFlow()
{
	m_flow = true;
	m_sprite.setTexture(ResourcesImages::getInstance().getTexture(ResourcesImages::vectorIconType::i_full_pipe2));
}
//-----------------------------------------------------------------------------
void PipeStraight::printNoflow()
{
	m_flow = false;
	m_sprite.setTexture(ResourcesImages::getInstance().getTexture(ResourcesImages::vectorIconType::i_empty_pipe2));

}