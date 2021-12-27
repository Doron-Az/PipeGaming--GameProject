#include "MainMenu.h"

#include <iostream> 

MainMenu::MainMenu() :m_height(HEIGHT_MENU_WINDOW), m_width(WIDTH_MENU_WINDOW)
{
	m_sprite.setTexture(ResourcesImages::getInstance().
		getTexture(ResourcesImages::vectorIconType::i_startManu));
	m_window.create(sf::VideoMode(m_width, m_height), "Opening");
}
//-----------------------------------------------------------------------------
void MainMenu::run()
{
	m_window.create(sf::VideoMode(m_width, m_height), "Opening");

	while (m_window.isOpen())
	{
		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			m_locationMouse = m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });

			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;

			case sf::Event::MouseButtonReleased:
				auto clickLocation = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				switch (event.mouseButton.button)
				{
				case sf::Mouse::Button::Left:
					switch (clickOnMenu(clickLocation))
					{
					case e_play:
						m_window.close();
						break;
					case e_exit:
						exit(EXIT_SUCCESS);
						break;
					}
					break;
				}
				break;
			}
		}
		draw();
	}
}
//-----------------------------------------------------------------------------
void MainMenu::draw()
{
	//makeFrame(m_locationMouse);

	m_window.clear();
	m_window.draw(m_sprite);

	if (m_isFrame)
		m_window.draw(m_frame);

	m_window.display();
}
//-----------------------------------------------------------------------------
//to find the clicks 
int MainMenu::clickOnMenu(sf::Vector2f clickLocation)
{
	if (clickLocation.x > 10.f && clickLocation.x < 145.f)
		if (clickLocation.y > 13.f && clickLocation.y < 88.f)
			return e_exit;

	if (clickLocation.x > 270.f && clickLocation.x < 730.f)
		if (clickLocation.y > 490.f && clickLocation.y < 685.f)
			return e_play;

	return e_nothing;
}
