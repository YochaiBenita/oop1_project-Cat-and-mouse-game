#pragma once
#include "Controller.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <sstream>


Resources Controller::m_resources;
int Controller::m_score = 0;
Level* Controller::m_currLevel(nullptr);
sf::Text Controller::m_text;

Controller::Controller() :
	m_menu()
{
	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(24);
	m_text.setFont(*m_resources.getFont());
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

void Controller::add_score(int score)
{
	m_score += score;;
}

//sf::Font* Controller::getFont()
//{
//	return m_resources.getFont();
//}


void Controller::draw_data(sf::RenderWindow& wind)
{
	std::ostringstream a;
	for (int i = 0; i < 3; i++)
	{
		std::ostringstream a;
		a << (m_currLevel->get_keys());
		m_text.setString(a.str());


		auto sp = sf::Sprite(*Controller::getTexutre(1));
		sp.setPosition(sf::Vector2f(10, 50 + 100 * i));

		m_text.setPosition(sp.getPosition() + sf::Vector2f(30, 0));

		wind.draw(sp);
		wind.draw(m_text);
	}


}





	
