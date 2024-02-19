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


Controller::Controller()
	: m_level(nullptr), m_levels_name(readLevelNames()) 
{
}

Controller::~Controller()
{

}






	
