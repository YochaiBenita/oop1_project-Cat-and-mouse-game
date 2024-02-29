#include "Resources.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Resources::Resources()
{
	auto line = std::string();
	auto file = std::ifstream("playlist.txt");

	//level names
	while (std::getline(file, line))
	{
		m_levels_name.push_back(line);
	}

	//texures
	readData(m_texures, m_FileNames, NUM_OF_TEXTURES);
	readData(m_data_texures, m_DataTexturesNames, NUM_OF_DATA_TEXTURES);
	readData(m_backgroungs, m_BackgroundsNames, NUM_OF_BACKGROUNDS);
	readData(m_buttons_texures, m_Button, NUM_OF_BUTTONS);
	readData(m_messages_texures, m_WinLoss, NUM_OF_MESSAGES);

	m_backgroungs[2].setRepeated(true);
	m_backgroungs[3].setRepeated(true);

	//sounds
	for (int i = 0; i < NUM_OF_SOUNDES; i++)
	{
		m_sound_buffer[i].loadFromFile(m_SoundNames[i]);
	}

	//font
	m_font.loadFromFile(m_font_name);
	
}

void Resources::readData(sf::Texture arr[], std::string names[], int num_of_objects)
{
	for (int i = 0; i < num_of_objects; i++)
	{
		arr[i].loadFromFile(names[i]);
	}
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
