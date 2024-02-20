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
			col = 0;
			row++;
			continue;
		}
		
		if (c != ' ')
		{
			if (c == '%' || c == '^')
			{
				auto temp = new_moving(c, col, row);
				if (c == '^')
				{
					m_movings.push_back(temp);
				}
				else		//for mouse
				{
					m_movings.insert(m_movings.begin(),temp);
				}
			}
			else
			{
				//static objects
				
				//auto temp = new_static(c, col, row);
				//m_statics.push_back(temp);
			}
		}
		col++;		
	}

}



bool Level::play()
{
	sf::RenderWindow window(sf::VideoMode(300, 300), "mouse and cat");
	
	while (window.isOpen())
	{
		sf::Clock clock;
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
				break;
			}
		}

		const auto deltaTime = clock.restart();
		for (int i = 0; i < m_movings.size(); i++)
		{
			deltaTime.asSeconds();
			//m_movings[i]->move(deltaTime.asSeconds());
			m_movings[i]->draw(window);
		}

		window.display();
	}
}

void Level::reset_locations()
{
	for (int i = 0; i < m_movings.size(); i++)
	{
		m_movings[i]->reset_location();
	}
}

std::unique_ptr <Moving_object> Level::new_moving(char c, int col, int row)
{
	if (c == '^')
	{
		auto cat = Cat(col, row);
		return std::make_unique<Moving_object>(Cat(col, row));
	}
	auto mouse = Mouse(col, row);
	return std::make_unique<Moving_object>(mouse);
}

std::unique_ptr<Static_object> Level::new_static(char c, int col, int row)
{
	if (c == '*')
	{
		auto cheese = Cheese(col, row);
		return std::make_unique<Static_object>(cheese);
	}

	auto mouse = Mouse(col, row);
	return std::make_unique<Static_object>(mouse);
}
