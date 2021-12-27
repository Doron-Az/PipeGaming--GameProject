#include "Board.h"

using namespace std;

Board::Board() : m_level(0), m_sinkCounter(0), m_height(0), m_width(0)
{
	srand((unsigned int)time(NULL));

	m_boardFile.open("levels.txt");

	if (m_boardFile.fail())
		throw std::out_of_range("Cannot find file, please check the file name and try again.\n");

	readNameLevelFile();
	m_boardFile = openFile(0);
	scanLevelFromFile();
	scanObjectsIconToMap();
}
//-----------------------------------------------------------------------------
void Board::scanLevelFromFile()
{

	auto level_file = openFile(m_level);

	char c;

	m_sinkCounter = 0; //reset the counter of sink current level

	m_boardFile >> m_height;
	m_boardFile >> std::noskipws >> c;

	m_boardFile >> m_width;
	m_boardFile >> std::noskipws >> c;

	m_charMap.clear();
	m_charMap.resize((int)m_height);


	for (int row = 0; row < m_height; row++) {
		for (int col = 0; col < m_width + 1; col++) { //+1 for the '\n'
			m_boardFile >> std::noskipws >> c;
			if (c != '\n') {
				m_charMap[row].push_back(c);
				if (c == c_sinkChar)
					m_sinkCounter++;
			}
		}
	}
}
//-----------------------------------------------------------------------------
void Board::readNameLevelFile()
{
	std::string fileName;

	while (!m_boardFile.eof())
	{
		m_boardFile >> fileName;
		m_levelsFileNames.push_back(fileName);
	}

	m_boardFile.close();
}
//-----------------------------------------------------------------------------
std::ifstream Board::openFile(int level)
{
	std::ifstream tempFile;
	tempFile.open(m_levelsFileNames[level]);

	if (tempFile.fail())
		throw std::out_of_range("Cannot find file, please check the file name and try again.\n");

	return tempFile;
}
//-----------------------------------------------------------------------------
void Board::scanObjectsIconToMap()
{
	for (int height = 0; height < m_height; height++) {
		for (int width = 0; width < m_width; width++) {
			createObject(m_charMap[height][width], (float)(height), (float)(width));
		}
	}
}
//-----------------------------------------------------------------------------
void Board::createObject(char type, float height, float width)
{
	auto matrixGameObject = createGameObject(type, height, width);

	if (matrixGameObject)
	{
		m_matrixGameObject.emplace_back(matrixGameObject);
		return;
	}
}
//-----------------------------------------------------------------------------
std::shared_ptr<GameObject> Board::createGameObject(char type, float height, float width)
{
	height *= PIXEL_SIZE;
	width *= PIXEL_SIZE;

	switch (type)
	{
	case ObjectType::c_pipeCossSectionChar:
		return std::make_unique<PipeCossSection>(height, width, getRandNumber());
	case ObjectType::c_pipeRoundedChar:
		return std::make_unique<PipeRounded>(height, width, getRandNumber());
	case ObjectType::c_pipeStraightChar:
		return std::make_unique<PipeStraight>(height, width, getRandNumber());
	case ObjectType::c_tapChar:
		return std::make_unique<Tap>(height, width, getRandNumber());
	case ObjectType::c_sinkChar:
		return std::make_unique<Sink>(height, width);
	case ObjectType::c_spaceChar:
		return std::make_unique<Space>(height, width); 
	}
	throw std::out_of_range("Cannot find file, please check the file name and try again.\n");
}
//-----------------------------------------------------------------------------
void Board::draw(sf::RenderWindow& window)
{

	for (auto& gameObject : m_matrixGameObject)
		gameObject->draw(window);
}
//-----------------------------------------------------------------------------
float Board::getHeight() const
{
	return m_height;
}
//-----------------------------------------------------------------------------
float Board::getWidth() const
{
	return m_width;
}
//-----------------------------------------------------------------------------
int Board::getRandNumber()
{
	return (rand() % 4) + 1;
}
//-----------------------------------------------------------------------------
void Board::rotateObject(sf::Vector2f m_locationClick,const char side)
{
	sf::Vector2i objectLocation((int)(m_locationClick.x / PIXEL_SIZE), (int)(m_locationClick.y / PIXEL_SIZE));


	for (auto& gameObject : m_matrixGameObject)
	{
		if (objectLocation.x == (int)(gameObject->getSprite().getPosition().x / PIXEL_SIZE) &&
			objectLocation.y == (int)(gameObject->getSprite().getPosition().y / PIXEL_SIZE))
		{
			typeid(MovingObject);
			if (typeid(*gameObject) != typeid(Sink))
				switch (side) {
				case 'l':
					gameObject->myRotate(LEFT);
					break;
				case 'r':
					gameObject->myRotate(RIGHT);
					break;

				}
		}
	}
}
//-----------------------------------------------------------------------------
void Board::fillGraph()
{
	int counter = 0;

	removeNeighbors();

	for (auto& gameObject : m_matrixGameObject)
		m_graph.addVertex(gameObject);

	for (auto& gameObject : m_matrixGameObject)
	{
		addNeighbors(counter, gameObject);
		counter++;
	}
	m_graph.isBfsFoundSink();
}
//-----------------------------------------------------------------------------
void Board::addNeighbors(int counter, std::shared_ptr<GameObject>& gameObject)
{
	int temp;
	if (counter > m_width && (counter - m_width <= 0))
	{
		temp = counter - (int)m_width;
		if (gameObject->getDirection(GameObject::Direction::d_up))
			if (m_matrixGameObject[temp]->getDirection(GameObject::Direction::d_down)) {
				m_graph.addEdge(gameObject, m_matrixGameObject[temp], 1);
			}
	}

	if (counter + m_width < m_matrixGameObject.size())
	{
		temp = counter + (int)m_width;
		if (gameObject->getDirection(GameObject::Direction::d_down))
			if (m_matrixGameObject[temp]->getDirection(GameObject::Direction::d_up)) {
				m_graph.addEdge(gameObject, m_matrixGameObject[temp], 1);
			}
	}
	temp = counter + 1;

	if (((counter % (int)m_width) != (m_width - 1)) && temp < m_matrixGameObject.size())
	{
		if (gameObject->getDirection(GameObject::Direction::d_right))
			if (m_matrixGameObject[temp]->getDirection(GameObject::Direction::d_left)) {
				m_graph.addEdge(gameObject, m_matrixGameObject[temp], 1);
			}
	}

	if ((counter % (int)m_width) != 0 && counter - 1 >= 0)
	{
		temp = counter - 1;
		if (gameObject->getDirection(GameObject::Direction::d_left))
			if (m_matrixGameObject[temp]->getDirection(GameObject::Direction::d_right)) {
				m_graph.addEdge(gameObject, m_matrixGameObject[temp], 1);
			}
	}
}
//-----------------------------------------------------------------------------
void Board::removeNeighbors()
{
	m_graph.graphReset();
}
//-----------------------------------------------------------------------------
bool Board::checkIfLevelFinished()
{
	int sinkCounter = 0;

	for (auto& gameObject : m_matrixGameObject)
	{
		if (typeid(*gameObject) == typeid(Sink))
			if (gameObject->isFlow())
				sinkCounter++;
	}
	if (sinkCounter == m_sinkCounter)
		return true;

	return false;
}
//-----------------------------------------------------------------------------
void Board::nextLevel()
{
	m_level++;
	m_boardFile.close();
	m_boardFile = openFile(m_level);
	m_charMap.clear();
	m_matrixGameObject.clear();

	scanLevelFromFile();
	scanObjectsIconToMap();

}
//-----------------------------------------------------------------------------
int Board::getLevel()
{
	return m_level + 1;
}
//-----------------------------------------------------------------------------
void Board::setLevel(int level)
{
	m_level = level;
}
//-----------------------------------------------------------------------------
int Board::getNumOfLevels()const
{
	return (int)m_levelsFileNames.size();
}
//-----------------------------------------------------------------------------
