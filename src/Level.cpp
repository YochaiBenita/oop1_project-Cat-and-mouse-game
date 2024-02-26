#pragma once
#include "Level.h"



Level::Level(std::string fileName)
{
	char c;
	auto file = std::ifstream(fileName);
	int row = 0;
	int col = 0;

	while (file.get(c))
	{
		if (c == '\n')
		{
			m_width = col;
			col = 0;
			row++;
			continue;
		}
		
		if (c != ' ')
		{
			if (c == '^')
			{
				m_movings.push_back(new_moving(c, col, row));
			}
			else if(c=='%')
			{
				m_movings.insert(m_movings.begin(), new_moving(c, col, row));
			}
			else if (c=='*' || c=='D' || c=='F' || c=='D' || c=='#')
			{
				m_statics.push_back(new_static(c, col, row));
			}
		}
		col++;		
	}
	m_hight = row;

}



bool Level::play()
{
	sf::RenderWindow window(sf::VideoMode(m_width*IMAGESIZE, m_hight*IMAGESIZE), "mouse and cat");
	sf::Clock clock;

	while (window.isOpen())
	{
		
		window.clear(sf::Color::White);

		for (int i = 0; i < m_statics.size(); i++)
		{
			m_statics[i]->draw(window);
		}
		
		if (auto event = sf::Event(); window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				m_exit = true;
				break;
			}
		}

		const auto deltaTime = clock.restart();
		for (int i = 0; i < m_movings.size(); i++)
		{
			/*
			m_moving[i]->set_direction(m_moving[0]);
			for (int x=0; x<m_static.size(); x++)
			{
				if (m_moving[i].checkcollision(m_static[i]))
				{
					
				}
				//עוד לולאה לחיות

			}

			m_movings[i]->move(deltaTime.asSeconds());
			m_movings[i]->draw(window);
			*/


			//destenation
			//for (collision?)
	//		{

//			}

			m_movings[i]->move(deltaTime.asSeconds());
			handleCollision(*(m_movings[i]));
			m_movings[i]->draw(window);
		}

		window.display();
	}
	return true;
}

void Level::reset_locations()
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
	//case '$':
	//	return std::make_unique<Gift>(col, row);
	case 'D':
		return std::make_unique<Door>(col, row);
	}
}

void Level::handleCollision(Moving_object& obj)
{
	for (int i = 0; i < m_movings.size(); ++i)  //collision between players
	{
		if (obj.checkCollision(*m_movings[i]))
		{
			obj.collision(*m_movings[i]);
		}
	}
	for (int i = 0; i < m_statics.size(); ++i) //collision between player and static object
	{
		if (obj.checkCollision(*m_statics[i]))
		{
			obj.collision(*m_statics[i]);
			if ((*m_statics[i]).to_erase())
			{
				//מחיקה
			}
		}
	}
	//m_board.collision(gameObject, *this);
}

