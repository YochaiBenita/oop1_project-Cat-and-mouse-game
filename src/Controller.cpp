#pragma once
#include "Controller.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <sstream>


//Resources Controller::m_resources;
int Controller::m_score = 0;
Level* Controller::m_currLevel(nullptr);
//sf::Text Controller::m_text;
//sf::Sprite Controller::m_dataSP[3];
//Menu Controller::m_menu;

Controller::Controller()
{

}

Controller::~Controller() {}

void Controller::run()
{
	//m_music.play();
	while (!m_to_exit) 
	{
		while (m_life > 0 && m_levelNumber < Resources::getInstance().numOfLevels() )
		{
			if (m_currLevel == nullptr) {
				m_currLevel = new Level(Resources::getInstance().getLevelNameAt(m_levelNumber));
			}

			if (m_currLevel->play())
			{
				m_to_exit = m_currLevel->to_exit();
				delete m_currLevel;
				if (m_to_exit) {
					break;
				}
				m_currLevel = nullptr;
				m_levelNumber++;
				//add_score();

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
	//m_music.stop();
	//m_music.~Music();
}
//
//sf::Texture* Controller::getTexutre(int index)
//{
//	return m_resources.getTextureAt(index);
//}
//
//sf::Texture* Controller::getBackground(int index)
//{
//	return m_resources.getBackground(index);
//}
//
//sf::Texture* Controller::getDataTexure(int index)
//{
//	return m_resources.getDataTexure(index);
//}
//
//sf::SoundBuffer* Controller::getSoundBuffer(int index)
//{
//	return m_resources.getSoundBuffer(index);
//}


void Controller::add_score(int score)
{
	m_score += score;;
}
//
//sf::Font* Controller::getFont()
//{
//	return Resources::getInstance().getFont();
//}

//
//void Controller::draw_data(sf::RenderWindow& wind)
//{
//	m_menu.draw_data(wind);
//
//}

int* Controller::get_life_ptr()
{
	return &m_life;
}

int* Controller::get_score_ptr()
{
	return &m_score;
}

void Controller::reset_controller()
{
	m_life = 3;
	m_score = 0;
	m_levelNumber = 0;
	m_to_exit = false;
	m_currLevel = nullptr;
}




	
