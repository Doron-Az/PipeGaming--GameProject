#include "Controller.h"

Controller::Controller():m_height(0), m_width(0), m_information(0, 0, 0, 0, 0),
m_score(0), m_numOfClicks(0), m_isCompleted(false)
{
        m_height = (int)(m_board.getHeight() * PIXEL_SIZE);
        m_width = (int)(m_board.getWidth() * PIXEL_SIZE);

        (m_width < MIN_WIDTH_WINDOW) ? m_widthWindow =(int) MIN_WIDTH_WINDOW : m_widthWindow = m_width;
        m_heightWindow = (int)(m_height + PIXEL_SIZE);

        m_background.setTexture(ResourcesImages::getInstance().getTexture(ResourcesImages::vectorIconType::i_background1));
        m_information.setPosition((float)m_height);
        m_information.setInformation(0, 0, 1);

        ResourcesSounds::getInstance().playLoop(ResourcesSounds::vectorSoundType::s_BackGroundMusic);

        MainMenu().run();
    
}
//-----------------------------------------------------------------------------
void Controller::run()
{

    auto window = sf::RenderWindow(sf::VideoMode(m_widthWindow, m_heightWindow), "Pipe Game");

    while (window.isOpen())
    {
            if (auto event = sf::Event{}; window.waitEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseMoved:
                    m_locationMove = window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
                    break;

                case sf::Event::MouseButtonReleased:
                    if (!m_isCompleted)
                    {
                        ResourcesSounds::getInstance().playSound(ResourcesSounds::vectorSoundType::s_Click);
                        m_numOfClicks++;
                        m_locationClick = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                        switch (event.key.code)
                        {
                     
                        case::sf::Mouse::Left:
                            m_board.rotateObject(m_locationClick , CHAR_LEFT);
                            break;

                        case::sf::Mouse::Right:
                            m_board.rotateObject(m_locationClick, CHAR_RIGHT);
                            break;

                        }
                        m_board.fillGraph();
                        checkIfLevelCompleted(window);
                    }
                    break;

                case sf::Event::KeyPressed:

                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        window.close();
                        exit(EXIT_SUCCESS);
                        break;
                    }
                    if (event.key.code == sf::Keyboard::Enter)
                    {
                        if (m_isCompleted)
                        {
                            nextLevel(window);
                            m_isCompleted = false;
                        }
                        break;
                    }

                }
                if (!m_isCompleted)
                {
                    m_information.setInformation(m_score, m_numOfClicks, m_board.getLevel());
                    window.clear();
                    window.draw(m_background);
                    m_board.draw(window);
                    window.draw(printOutLine());
                    m_information.draw(window);
                    window.display();
                }
            }
        
    }
}
//-----------------------------------------------------------------------------
void Controller::nextLevel(sf::RenderWindow& window)
{
    m_numOfClicks = 0;
    m_score += FINISH_LEVEL_SCORE * m_board.getLevel();
    m_board.nextLevel();
    m_height = int(m_board.getHeight() * PIXEL_SIZE);
    m_width = int(m_board.getWidth() * PIXEL_SIZE);
    (m_width <(int) MIN_WIDTH_WINDOW) ? m_widthWindow =(int) MIN_WIDTH_WINDOW : m_widthWindow = m_width;
    m_heightWindow =int( m_height + PIXEL_SIZE);

    window.create(sf::VideoMode(m_widthWindow, (unsigned int)(m_heightWindow)), "Pipe Game");

    m_information.setPosition((float)m_height);

    m_information.setInformation(m_score, m_numOfClicks, m_board.getLevel());
}
//-----------------------------------------------------------------------------
sf::RectangleShape Controller::printOutLine()
{
    float newLocationX = floor(((m_locationMove.x) + PIXEL_SIZE)/ PIXEL_SIZE) * PIXEL_SIZE - PIXEL_SIZE;
    float newLocationY = floor(((m_locationMove.y) + PIXEL_SIZE) / PIXEL_SIZE) * PIXEL_SIZE - PIXEL_SIZE;

    sf::Vector2f newLocation(newLocationX,newLocationY);
    sf::Vector2f size(PIXEL_SIZE, PIXEL_SIZE);
    sf::RectangleShape rec(size);

    rec.setOutlineThickness(2);
    rec.setFillColor(sf::Color::Transparent);
    rec.setOutlineColor(sf::Color::Blue);
    rec.setPosition(newLocation);

    return rec;
}
//-----------------------------------------------------------------------------
void Controller::openWindowNextLevel(sf::RenderWindow& window)
{
    sf::Sprite over;

    over.setTexture(ResourcesImages::getInstance().getTexture(ResourcesImages::vectorIconType::i_levelCompleted));
    over.setPosition(window.getView().getCenter().x - WINDOWS_MASSAGE_WIDTH /2, 
        window.getView().getCenter().y - WINDOWS_MASSAGE_HEIGHT/2);


    ResourcesSounds::getInstance().playSound(ResourcesSounds::vectorSoundType::s_FinishLevel);

    window.clear();
    window.draw(m_background);
    m_board.draw(window);
    m_information.draw(window);
    window.draw(over);
    window.display();

    m_isCompleted = true;
}
//-----------------------------------------------------------------------------
void Controller::endOfTheGame(sf::RenderWindow& window)
{
    sf::Sprite finish;

    finish.setTexture(ResourcesImages::getInstance().getTexture(ResourcesImages::vectorIconType::i_gameFinish));
    finish.setPosition(window.getView().getCenter().x - 250, window.getView().getCenter().y - 150);

    ResourcesSounds::getInstance().playSound(ResourcesSounds::vectorSoundType::s_FinishLevel);

    window.clear();
    window.draw(m_background);
    m_board.draw(window);
    m_information.draw(window);
    window.draw(finish);
    window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    window.close();

    exit(EXIT_SUCCESS);
}
//-----------------------------------------------------------------------------
void Controller::checkIfLevelCompleted(sf::RenderWindow& window)
{
    if (m_board.checkIfLevelFinished())
    {
        if (m_board.getLevel() != m_board.getNumOfLevels())
            openWindowNextLevel(window);
        else
            endOfTheGame(window);
    }
}
