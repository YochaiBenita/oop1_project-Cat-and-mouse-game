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
			if (c == '^')
			{
				m_movings.push_back(new_moving(c, col, row));
				////debug
				//{
				//	auto w = sf::RenderWindow(sf::VideoMode(300, 300), "test");
				//	m_movings[0]->draw(w);
				//	w.display();
				//	int a;
				//	std::cin >> a;
				//}
			}
			else if(c=='%')		//for mouse
			{
				m_movings.insert(m_movings.begin(), new_moving(c, col, row));
			}
			else
			{
				m_statics.push_back(new_static(c, col, row));
			}
		}
		col++;		
	}

}



bool Level::play()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "mouse and cat");
	sf::Clock clock;

	while (window.isOpen())
	{
		
		window.clear(sf::Color::Blue);

		for (int i = 0; i < m_statics.size(); i++)
		{
			//m_statics[i]->draw(window);
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
			//m_movings[i]->move(deltaTime.asSeconds());
			m_movings[i]->draw(window);
		}

		window.display();

		int a;
		std::cin >> a;
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
	//	//return std::make_unique<Gift>(col, row);
	case 'D':
		return std::make_unique<Door>(col, row);
	//{}
	//return std::make_unique<Static_object>(1, col, row);
	}
}
