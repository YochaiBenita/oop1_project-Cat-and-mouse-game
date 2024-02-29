#pragma once
#include "Level.h"
#include <iostream>
#include "Resources.h"
#include "Controller.h"
#include "Menu.h"

int Level::m_keys =0;
Data Level::m_data[];
int Data::num_of_data = 0;

Level::Level(std::string fileName)
{
	m_cats = 0;
	char c;
	auto file = std::ifstream(fileName);
	//int row = 0;
	int col = 0;

	file >> m_time;
	file.get(c);

	while (file.get(c))
	{
		if (c == '\n')
		{
			m_width = col;
			col = 0;
			m_hight++;
			continue;
		}
		
		if (c != ' ')
		{
			if (c == '^')
			{
				m_movings.push_back(new_moving(c, col, m_hight));
				m_cats++;
			}
			else if(c=='%')
			{
				m_movings.insert(m_movings.begin(), new_moving(c, col, m_hight));
			}
			else if (c=='*' || c=='D' || c=='F' || c=='D' || c=='#' || c=='$')
			{
				m_statics.push_back(new_static(c, col, m_hight));
			}
		}
		col++;
	}
	

	m_background = sf::RectangleShape(sf::Vector2f(m_width * IMAGESIZE /* + TOPLEFT.x*/, m_hight * IMAGESIZE /* + TOPLEFT.y*/));
	m_background.setTexture(Resources::getInstance().getBackground(2));
	m_background.setTextureRect(sf::IntRect(TOPLEFT.x, TOPLEFT.y, m_width * IMAGESIZE /* + TOPLEFT.x*/, m_hight * IMAGESIZE /* + TOPLEFT.y*/));
	m_background.setPosition(TOPLEFT);

	m_background_data = sf::RectangleShape(sf::Vector2f(TOPLEFT.x, m_hight * IMAGESIZE + TOPLEFT.y));
	m_background_data.setTexture(Resources::getInstance().getBackground(3));
	m_background_data.setTextureRect(sf::IntRect(0, 0,TOPLEFT.x, m_hight * IMAGESIZE + TOPLEFT.y));

	m_timer = (int)m_time;

	m_keys = 0;

}



bool Level::play()
{
	sf::RenderWindow window(sf::VideoMode(m_width * IMAGESIZE + TOPLEFT.x, m_hight * IMAGESIZE + TOPLEFT.y), "mouse and cat");
	
	//sf::Clock clock;

	while (window.isOpen() &&
		Cheese::get_cheese_num()>0 &&
		m_timer > 0)
	{
		
		window.clear(sf::Color::White);
		window.draw(m_background);

		draw_data(window);

		for (int i = 0; i < m_statics.size(); i++)
		{
			m_statics[i]->draw(window);
		}
		
		if (auto event = sf::Event(); window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_exit = true;
				window.close();
				break;
			}
		}

		auto deltaTime = m_clock.restart();

		m_timer -= deltaTime.asSeconds();
		m_freezing_timer -= deltaTime.asSeconds();

		if (m_movings[0]->freeze_status() && m_freezing_timer < 0)
		{
			freeze_gift(false);
		}

		std::cout << "move\n";

		for (int i = 0; i < m_movings.size(); i++)
		{
			m_movings[i]->move(deltaTime.asSeconds(), m_movings[0].get());

			if (handleCollision(*m_movings[i])) //if the mouse has died
			{
				return false;
			}

			m_movings[i]->draw(window);
		}
		
		window.display();
	}
	return (m_timer >= 0) ? true : false;

}

void Level::reset_level()
{
	for (int i = 0; i < m_movings.size(); i++)
	{
		m_movings[i]->reset_location();
	}
}

bool Level::to_exit() const
{
	return m_exit;
}

void Level::add_key()
{
	m_keys++;
}

void Level::use_key()
{
	m_keys--;
}

int Level::get_keys()
{
	return m_keys;
}

std::unique_ptr <Moving_object> Level::new_moving(char c, int col, int row)
{
	if (c == '^')
	{
		return std::make_unique<Cat>(col, row);
	}
	return std::make_unique<Mouse>(col, row);
}

std::unique_ptr<Static_object> Level::new_static(char c, int col, int row)
{ 
	switch (c)
	{
	case '#':
		return std::make_unique<Wall>(col, row);
	case 'F':
		return std::make_unique<Key>(col, row);
	case '*':
		return std::make_unique<Cheese>(col, row);
	case '$':
		switch (rand() % 4)
		{
		case 0:
			return std::make_unique<Gfreeze>(col, row);
		case 1:
			return std::make_unique<Gkill>(col, row);
		case 2:
			return std::make_unique<Glife>(col, row);
		case 3:
			return std::make_unique<Gtime>(col, row);
		}
	case 'D':
		return std::make_unique<Door>(col, row);
	}
}

bool Level::handleCollision(Moving_object& obj)
{
	check_move(obj);
	for (int j = 0; j < m_statics.size(); j++)
	{
		if (m_statics[j]->checkCollision(obj))
		{
			bool to_delete = m_statics[j]->collision(obj);
			if (to_delete)
			{
				m_statics.erase(m_statics.begin() + j);
			}
			break;
		}
	}

	for (int j = 0; j < m_movings.size(); j++)
	{
		if (m_movings[j]->checkCollision(obj))
		{
			bool kill = m_movings[j]->collision(obj);
			if (kill)
			{
				return true;
				//kill mouse
			}
			break;
		}
	}
	return false;
}

void Level::check_move(Moving_object & player)
{
	
	sf::FloatRect playerBounds = player.get_sprite().getGlobalBounds();
	if (playerBounds.top < 0 || playerBounds.left < TOPLEFT.x
		|| ((playerBounds.left) - TOPLEFT.x) / IMAGESIZE +1 > m_width
		|| (playerBounds.top) / IMAGESIZE +1 > m_hight)
	{
		player.set_position(player.get_previous_loc());
	}
}

void Level::add_to_time(int time)
{
	m_timer += time;
}

int Level::num_of_moving()
{
	return (int)m_movings.size();
}

void Level::pop_moving()
{
	m_movings.pop_back();
}

int Level::original_cats()
{
	return m_cats;
}

//---------------------------------------------
void Level::draw_data(sf::RenderWindow& wind)
{
	//m_data[0].src = m_controller.get_timer_ptr(); //time
//m_data[1].src = m_controller.get_life_ptr(); //life
//m_data[2].src = m_controller.get_score_ptr();
//m_data[3].src = m_controller.get_score_ptr(); //keys
	m_data[0].m_text.setString(std::to_string((int)m_timer));
	m_data[1].m_text.setString(std::to_string(Controller::get_life()));
	m_data[2].m_text.setString(std::to_string(Controller::get_score()));
	m_data[3].m_text.setString(std::to_string(m_keys));

	wind.draw(m_background_data);

	for (int i = 0; i < NUM_OF_DATA_TEXTURES; i++)
	{
		wind.draw(m_data[i].m_data);
		wind.draw(m_data[i].m_text);
	}
}

void Level::freeze_gift(bool data)
{
	for (int i = 0; i < m_movings.size(); i++)
	{
		m_movings[i]->set_freeze(data);
	}
	m_freezing_timer = FREEZING_TIME;
}

float Level::get_timer()
{
	return m_timer;
}

void Level::add_to_score(int points)
{
	m_level_score += points;
}

int Level::get_level_score() const
{
	return m_level_score;
}


Data::Data()
{
	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(40);
	m_text.setFont(*Resources::getInstance().getFont());
	m_text.setOrigin(sf::Vector2f(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2));

	m_data.setTexture(*Resources::getInstance().getDataTexure(num_of_data));
	m_data.setPosition(sf::Vector2f(10, 20 + 100 * num_of_data));

	m_text.setPosition(m_data.getPosition() + sf::Vector2f(IMAGESIZE,IMAGESIZE));

	num_of_data++;

}

