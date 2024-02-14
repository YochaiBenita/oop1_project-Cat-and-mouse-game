#pragma once
#include "Level.h"



Level::Level(std::string fileName)
{
	std::string line;
	auto file = std::ifstream(fileName);

	while (std::getline(file, line))
	{
		m_board.push_back(line);
	}

	count_elements();

}



void Level::play()
{


}