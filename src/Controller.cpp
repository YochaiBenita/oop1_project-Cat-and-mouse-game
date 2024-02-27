#pragma once
#include "Controller.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <sstream>


Resources Controller::m_resources;
int Controller::m_score = 0;
Level* Controller::m_currLevel(nullptr);
//sf::Text Controller::m_text;
//sf::Sprite Controller::m_dataSP[3];
Menu Controller::m_menu;

Controller::Controller()
{


}

Controller::~Controller() {}

void Controller::run()
{
	while (!m_to_exit) 
	{
		m_menu.show_menu();

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

				if (m_to_exit) {
					break;
				}

			}
			else
			{
				m_life--;
				m_currLevel->reset_locations();
			}
		}
		if (m_life > 0)
		{
			//m_menu winner
		}
		else
		{
			//new game?
			//m_menu losser
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

sf::Texture* Controller::getDataTexure(int index)
{
	return m_resources.getDataTexure(index);
}


void Controller::add_score(int score)
{
	m_score += score;;
}

sf::Font* Controller::getFont()
{
	return m_resources.getFont();
}


void Controller::draw_data(sf::RenderWindow& wind)
{
	m_menu.draw_data(wind);

}

int* Controller::get_live()
{
	return &m_life;
}

int* Controller::get_score()
{
	return &m_score;
}




	
