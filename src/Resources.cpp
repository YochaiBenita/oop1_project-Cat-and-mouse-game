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
	
	//sound \ font reading loop

}

sf::Texture Resources::getTextureAt(int index) const
{
	return m_texures[index];
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
