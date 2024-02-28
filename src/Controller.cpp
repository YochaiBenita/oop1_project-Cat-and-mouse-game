#pragma once
#include "Controller.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <sstream>


//Resources Controller::m_resources;
int Controller::m_score = 0;
Level* Controller::m_currLevel = nullptr;
int Controller::m_life = 3;
//sf::Text Controller::m_text;
//sf::Sprite Controller::m_dataSP[3];
//Menu Controller::m_menu;

Controller::Controller()
{

}

Controller::~Controller() {}

void Controller::run()
{
	//while (!m_to_exit) 
	{
		while (m_life > 0 && m_levelNumber < Resources::getInstance().numOfLevels() )
		{
			if (m_currLevel == nullptr) {
				m_currLevel = new Level(Resources::getInstance().getLevelNameAt(m_levelNumber));
			}

			if (m_currLevel->play()) //fhinished the level seccessfully
			{
				add_score(SCORE_OF_SUCCESS_LEVEL);
				add_score(SCORE_PER_CAT * (m_currLevel->original_cats()));

				m_to_exit = m_currLevel->to_exit();
				delete m_currLevel;

				if (m_to_exit) {
					break;
				}
				m_currLevel = nullptr;
				m_levelNumber++;

			}
			else
			{
				if (m_currLevel->get_timer() > 0) //eaten by a cat
				{
					m_life--;
					m_currLevel->reset_level();
				}
				else //end of time
				{
					m_life--;
					add_score(-m_currLevel->get_level_score());
					delete m_currLevel;
					m_currLevel = nullptr;
				}
			}
		}
		if (m_life > 0)
		{
			std::cout << "you won yhe game\n";
			//m_menu winner
		}
		else
		{
			delete m_currLevel;
			std::cout << "losserrrrrr\n";
			//new game?
			//m_menu losser
		}
	}
}



void Controller::add_score(int score)
{
	m_score += score;
	m_currLevel->add_to_score(score);
}

int Controller::get_life()
{
	return m_life;
}

int Controller::get_score()
{
	return m_score;
}

//int* Controller::get_timer_ptr()
//{
//	return m_currLevel->get_timer_ptr();
//}

void Controller::reset_controller()
{
	std::cout << "hi\n";
	m_life = 3;
	m_score = 0;
	m_levelNumber = 0;
	m_to_exit = false;
	m_currLevel = nullptr;
	Cheese::reset_cheese_counter();
}

void Controller::freeze_gift()
{
	m_currLevel->freeze_gift(true);
}

void Controller::life_gift()
{
	m_life++;
}

void Controller::kill_gift()
{
	if (m_currLevel->num_of_moving() > 1)
	{
		m_currLevel->pop_moving();
	}
}

void Controller::time_gift()
{
	m_currLevel->add_to_time(TIME_GIFT);
}




	
