#include "Resources.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Resources::Resources()
{
	auto line = std::string();
	auto file = std::ifstream("playlist.txt");
	//int i = 0;


	//level names
	while (std::getline(file, line))
	{
		m_levels_name.push_back(line);
	}

	//texures
	for (int i = 0; i < NUM_OF_TEXTURES; i++)
	{
		m_texures[i].loadFromFile(m_FileNames[i]);
	}

	//data texures
	for (int i = 0; i <NUM_OF_DATA_TEXTURES; i++)
	{
		m_data_texures[i].loadFromFile(m_DataTexturesNames[i]);
	}

	//backgrounds
	for (int i = 0; i < NUM_OF_BACKGROUNDS; i++)
	{
		m_backgroungs[i].loadFromFile(m_BackgroundsNames[i]);
	}
	m_backgroungs[2].setRepeated(true);
	m_backgroungs[3].setRepeated(true);

	//button texures
	for (int i = 0; i < NUM_OF_BUTTONS; i++)
	{
		m_buttons_texures[i].loadFromFile(m_Button[i]);
	}

	for (int i = 0; i < NUM_OF_MESSAGES; i++)
	{
		m_messages_texures[i].loadFromFile(m_WinLoss[i]);
	}

	//sounds
	for (int i = 0; i < NUM_OF_SOUNDES; i++)
	{
		m_sound_buffer[i].loadFromFile(m_SoundNames[i]);
	}

	//font
	m_font.loadFromFile("LoveDays-2v7Oe.ttf");
	

}

Resources& Resources::getInstance()
{
	static Resources instance;
	return instance;
}

sf::Texture* Resources::getTextureAt(int index)
{
	return &(m_texures[index]);
}

sf::Texture* Resources::getTextureMs(int index)
{
	return &(m_messages_texures[index]);
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
