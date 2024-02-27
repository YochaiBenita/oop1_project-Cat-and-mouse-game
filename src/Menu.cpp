#include "Menu.h"
#include "Controller.h"

Menu::Menu()
{
	m_background.setTexture(*Controller::getBackground(0));

	for (int i = 0; i < 3; i++)
	{
		m_button[i].setSize(sf::Vector2f(250, 70));
		m_button[i].setFillColor(sf::Color(160, 10, 10, 255));
		m_button[i].setPosition(sf::Vector2f(100, 70 + (100*i)));
	}
}

void Menu::show_menu()
{
	//auto r = sf::RectangleShape(sf::Vector2f(250, 70));
	//r.setFillColor(sf::Color(160, 10, 10, 255));
	//r.setPosition(sf::Vector2f(100, 100));


	sf::RenderWindow m_wind(sf::VideoMode(900, 500), "menu");
	m_wind.clear(sf::Color::White);
	while (m_wind.isOpen())
	{
		m_wind.draw(m_background);

		for (int i = 0; i < 3; i++)
		{
			m_wind.draw(m_button[i]);
		}


		m_wind.display();

		if (auto event = sf::Event(); m_wind.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_wind.close();
				break;
			case sf::Event::MouseButtonReleased:
				int option = handle_click(sf::Vector2f(event.mouseButton.x, event.mouseButton.y) );

				switch (option)
				{
				case 0:
					return;
				case 1:
					std::cout << "help\n";
					//show_menu
					//return;
					break;
				case 2:
					exit(EXIT_SUCCESS);
				default:
					break;
				}
			}
		}

	}
}

int Menu::handle_click(sf::Vector2f v2f)
{
	for (int i = 0; i < 3; i++)
	{
		if (m_button[i].getGlobalBounds().contains(v2f))
		{
			return i;
		}
	}
	return -1;
}

