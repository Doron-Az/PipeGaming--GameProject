#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <ostream>
#include <memory>

#include "Constant.h"
#include "Sink.h"
#include "PipeCossSection.h"
#include "PipeRounded.h"
#include "PipeStraight.h"
#include "Tap.h"
#include "Graph.h"
#include "Space.h"
#include "VertexObject.h"

#include <ctime>

class Board
{
public:


	Board();

	void scanLevelFromFile();
	void readNameLevelFile();
	std::ifstream openFile(int level);
	void scanObjectsIconToMap();
	void createObject(char type, float height, float width);
	std::shared_ptr<GameObject> createGameObject(char type, float height, float width);
	void draw(sf::RenderWindow& window);
	float getHeight()const;
	float getWidth()const;
	int getRandNumber();
	void rotateObject(sf::Vector2f m_locationClick, const char side);
	void fillGraph();
	void addNeighbors(int counter, std::shared_ptr<GameObject>& gameObject);
	void removeNeighbors();
	bool checkIfLevelFinished();
	void nextLevel();
	int getLevel();
	void setLevel(int);
	int getNumOfLevels()const;

	enum  ObjectType
	{
		c_pipeCossSectionChar = '+',
		c_pipeStraightChar = '-',
		c_pipeRoundedChar = '~',
		c_sinkChar = '#',
		c_tapChar = '&',
		c_spaceChar = ' ',
		c_endLineChar = '\n'
	};

private:

	bool m_firstFill = true,
		m_isTap = false;
	float m_width, m_height;
	int m_sinkCounter;
	int m_level;

	Graph<std::shared_ptr<GameObject>> m_graph;
	std::ifstream m_boardFile;
	std::vector<std::vector<char>> m_charMap;
	std::vector<std::string> m_levelsFileNames;
	std::vector<std::shared_ptr<GameObject>> m_matrixGameObject;

};