#pragma once
#include "Controller.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"

//static Resources m_resources = Resources();
Resources Controller::m_resources;//chat gpt

Controller::Controller() : 
	m_currLevel(nullptr)
{}

Controller::~Controller() {}

void Controller::run()
{
	//while (!m_to_exit) 
	{
		auto m = Menu();
		m.show_menu();

		while (m_life > 0 && m_levelNumber < m_resources.numOfLevels() )
		{
			if (m_currLevel == nullptr) {
				m_currLevel = new Level(m_resources.getLevelNameAt(m_levelNumber));
			}

			if (m_currLevel->play())
			{
				m_to_exit = m_currLevel->to_exit();
				delete m_currLevel;
				m_currLevel = nullptr;
				m_levelNumber++;
			}
			else
			{
				m_life--;
				m_currLevel->reset_locations();
			}
			
		}
	}
}

sf::Texture* Controller::getTexutre(int index)
{
	return m_resources.getTextureAt(index);
}
sf::Texture* Controller::getBackground(int index)
{
	return m_resources.getBackground(index);
}







	
