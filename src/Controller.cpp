#pragma once
#include "Controller.h"
#include <SFML/Graphics.hpp>


//global func
const std::vector <std::string> readLevelNames()
{
	std::vector<std::string> levelsName;
	std::string line;
	auto playList = std::ifstream("playlist.txt");

	while (playList >> line)
	{
		levelsName.push_back(line);
	}

	return levelsName;
}

sf::Texture* readTextures()
{
	sf::Texture* texures = new sf::Texture[NUM_OF_TXTR];

	for (int i = 0; i < NUM_OF_TXTR; i++)
	{
		texures[i].loadFromFile(FileNames[i]);
	}
	return texures;
}

//------------
Controller::Controller() : 
	m_currLevel(nullptr),
	m_levels_name(readLevelNames()),
	m_texures(readTextures()) {}

Controller::~Controller()
{

}

void Controller::play()
{
	while (m_life > 0 && m_levelNumber < m_levels_name.size())
	{
		if (m_currLevel == nullptr) {
			m_currLevel = new Level(m_levels_name[m_levelNumber]);
		}

		if (m_currLevel->play())
		{
			delete m_currLevel;
			m_currLevel = nullptr;
			m_levelNumber++;
		}
		else
		{
			m_life--;
			m_currLevel->reset_locations();
		}
		//exiting a level?
	}
}








	
