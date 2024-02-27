#include "Resources.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Resources::Resources()
{
	auto line = std::string();
	auto file = std::ifstream("playlist.txt");
	//int i = 0;

	while (std::getline(file, line))
	{
		m_levels_name.push_back(line);
	}

	for (int i = 0; i < NUM_OF_TEXTURES; i++)
	{
		m_texures[i].loadFromFile(m_FileNames[i]);
	}

	for (int i = 0; i < NUM_OF_BACKGROUNDS; i++)
	{
		m_backgroungs[i].loadFromFile(m_BackgroundsNames[i]);
	}
	m_backgroungs[2].setRepeated(true);

	m_font.loadFromFile("LoveDays-2v7Oe.ttf");

	for (int i = 0; i < 4; i++)
	{
		m_data_texures[i].loadFromFile(m_DataTexturesNames[i]);
	}
	
	//sound \ font reading loop

}

sf::Texture* Resources::getTextureAt(int index)
{
	return &(m_texures[index]);
}

sf::Texture* Resources::getDataTexure(int index)
{
	return &(m_data_texures[index]);
}

sf::Texture* Resources::getBackground(int index)
{
	return &(m_backgroungs[index]);
}

sf::Font* Resources::getFont()
{
	return &m_font;
}

std::string Resources::getLevelNameAt(int index) const
{
	return m_levels_name[index];
}

int Resources::numOfLevels() const
{
	return (int)m_levels_name.size();
}



//
////global func
//const std::vector <std::string> readLevelNames()
//{
//	std::vector<std::string> levelsName;
//	std::string line;
//	auto playList = std::ifstream("playlist.txt");
//
//	while (playList >> line)
//	{
//		levelsName.push_back(line);
//	}
//
//	return levelsName;
//}


//
//sf::Texture* readTextures()
//{
//	sf::Texture* texures = new sf::Texture[NUM_OF_TXTR];
//
//	for (int i = 0; i < NUM_OF_TXTR; i++)
//	{
//		texures[i].loadFromFile(FileNames[i]);
//	}
//	return texures;
//}
