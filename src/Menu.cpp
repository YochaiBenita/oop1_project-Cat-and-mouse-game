#include "Menu.h"
#include "Controller.h"

int Data::num_of_data = 0;


Menu::Menu() : m_data()
{
	m_background.setTexture(*Controller::getBackground(0));

	for (int i = 0; i < 3; i++)
	{
		m_button[i].setSize(sf::Vector2f(250, 70));
		m_button[i].setFillColor(sf::Color(160, 10, 10, 255));
		m_button[i].setPosition(sf::Vector2f(100, 70 + (100*i)));
	}

	m_data[0].src = Controller::get_score(); //time
	m_data[1].src = Controller::get_score(); //life
	m_data[2].src = Controller::get_score();
	m_data[3].src = Controller::get_score(); //keys

}

void Menu::show_menu()
{

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
			{
				int option = handle_click(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));

				switch (option)
				{
				case 0:
					return;
				case 1:
					show_help();
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
}

void Menu::show_help()
{
	sf::RenderWindow m_wind(sf::VideoMode(900, 500), "help");
	m_wind.clear(sf::Color::White);

	m_wind.clear();
	m_background.setTexture(*Controller::getBackground(1));
	m_wind.draw(m_background);
	m_background.setTexture(*Controller::getBackground(0));
	m_wind.display();

	while (true)
	{
		if (auto event = sf::Event(); m_wind.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_wind.close();
				return;
			}
		}
	}
	

}

void Menu::draw_data(sf::RenderWindow& wind)
{
	for (int i = 0; i < 4; i++)
	{
		m_data[i].update_data();
		wind.draw(m_data[i].m_data);
		wind.draw(m_data[i].m_text);
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



void Data::update_data()
{
	std::ostringstream a;
	a << *src;
	m_text.setString(a.str());
}


Data::Data()
{
	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(30);
	m_text.setFont(*Controller::getFont());

	m_data.setTexture(*Controller::getDataTexure(num_of_data));
	m_data.setPosition(sf::Vector2f(10, 50 + 100 * num_of_data));

	m_text.setPosition(m_data.getPosition());

	num_of_data++;
}
