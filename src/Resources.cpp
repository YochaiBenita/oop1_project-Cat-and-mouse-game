#include "Resources.h"
#include <SFML/Graphics.hpp>
#include <iostream>

sf::Texture Resources::m_texures[NUM_OF_TEXTURES];
sf::Texture Resources::m_data_texures[NUM_OF_DATA_TEXTURES];
sf::Texture Resources::m_backgroungs[NUM_OF_BACKGROUNDS];
sf::SoundBuffer Resources::m_sound_buffer[NUM_OF_SOUNDES];
sf::Font Resources::m_font;
std::vector<std::string> Resources::m_levels_name;
sf::Texture Resources::m_buttons_texures[NUM_OF_BUTTONS];



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

	for (int i = 0; i <NUM_OF_DATA_TEXTURES; i++)
	{
		m_data_texures[i].loadFromFile(m_DataTexturesNames[i]);
	}

	for (int i = 0; i < NUM_OF_BACKGROUNDS; i++)
	{
		m_backgroungs[i].loadFromFile(m_BackgroundsNames[i]);
	}
	m_backgroungs[2].setRepeated(true);

	for (int i = 0; i < NUM_OF_BUTTONS; i++)
	{
		m_buttons_texures[i].loadFromFile(m_Button[i]);
	}

	for (int i = 0; i < NUM_OF_SOUNDES; i++)
	{
		m_sound_buffer[i].loadFromFile(m_SoundNames[i]);
	}

	m_font.loadFromFile("LoveDays-2v7Oe.ttf");
	
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

sf::SoundBuffer* Resources::getSoundBuffer(int index)
{
	return &(m_sound_buffer[index]);
}

sf::Texture* Resources::getTextureButtons(int index)
{
	return &(m_buttons_texures[index]);;
}

sf::Font* Resources::getFont()
{
	return &m_font;
}

std::string Resources::getLevelNameAt(int index)
{
	return m_levels_name[index];
}

int Resources::numOfLevels()
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
