#pragma once
#include "Controller.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>

int Controller::m_score = 0;
Level* Controller::m_currLevel = nullptr;
int Controller::m_life = 3;
int Controller::m_levelNumber = 0;


Controller::Controller() {}

Controller::~Controller() 
{
	if (m_currLevel != nullptr)
		delete m_currLevel;
}

void Controller::run(sf::RenderWindow& m_wind)
{
	while (m_life > 0 && m_levelNumber < Resources::getInstance().numOfLevels() )
	{
		if (m_currLevel == nullptr)
		{
			m_currLevel = new Level(Resources::getInstance().getLevelNameAt(m_levelNumber));
		}

		if (m_currLevel->play()) // if fhinished the level seccessfully
		{
			play_sound(Resources::getInstance().getSoundBuffer(0));
			add_score(SCORE_OF_SUCCESS_LEVEL);
			add_score(SCORE_PER_CAT * (m_currLevel->original_cats()));

			m_to_exit = m_currLevel->to_exit();
			delete m_currLevel;
			m_currLevel = nullptr;

			if (m_to_exit)
			{
				return;
			}
			play_sound(Resources::getInstance().getSoundBuffer(0));
			m_levelNumber++;
		}

		else
		{
			m_life--;
			play_sound(Resources::getInstance().getSoundBuffer(1));

			if (m_currLevel->get_timer() > 0) //eaten by a cat
			{
				m_currLevel->reset_level();
			}

			else //end of time
			{
				add_score(-m_currLevel->get_level_score());
			}
		}
	}

	summerry_print(m_wind, (m_life > 0));
	delete m_currLevel;
	m_currLevel = nullptr;
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

int Controller::get_level_num()
{
	return m_levelNumber;
}

void Controller::reset_controller()
{
	m_life = 3;
	m_score = 0;
	m_levelNumber = 0;
	m_to_exit = false;
	m_currLevel = nullptr;
	Cheese::reset_cheese_counter();
}

void Controller::summerry_print(sf::RenderWindow& m_wind, bool win)
{
	m_wind.clear();

	auto sp = sf::Sprite(*Resources::getInstance().getBackground(0));
	m_wind.draw(sp);

	auto sp1 = sf::Sprite(*Resources::getInstance().getTextureMs(win));

	sp1.setOrigin(sp1.getLocalBounds().width / 2, sp1.getLocalBounds().height / 2);
	sp1.setPosition(sf::Vector2f(m_wind.getSize().x / 2, m_wind.getSize().y / 2));

	m_wind.draw(sp1);
	
	std::string str = "score: " + std::to_string(m_score) +
		" num of levels:" + std::to_string(m_levelNumber);

	auto text = sf::Text(str, *Resources::getInstance().getFont(), 40);
	text.setOrigin(sf::Vector2f(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2));
	text.setPosition(sp1.getPosition() + sf::Vector2f(0,130));
	text.setFillColor(sf::Color::Black);

	m_wind.draw(text);

	m_wind.display();

	sf::sleep(sf::seconds(3));
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

void Controller::play_sound(sf::SoundBuffer* sound)
{
	m_curr_sound.setBuffer(*sound);
	m_curr_sound.play();
}


	
