#include "Menu.h"
#include "Controller.h"

int Data::num_of_data = 0;
Data Menu::m_data[];


Menu::Menu()
{
	m_background.setTexture(*Resources::getBackground(0));

	for (int i = 0; i < NUM_OF_BUTTONS; i++)
	{
		m_button[i].setTexture(*Resources::getTextureButtons(i));
		m_button[i].setPosition(sf::Vector2f(250, 100 * (i+1)));
	}

	m_data[0].src = m_controller.get_life_ptr(); //time
	m_data[1].src = m_controller.get_life_ptr(); //life
	m_data[2].src = m_controller.get_score_ptr();
	m_data[3].src = m_controller.get_score_ptr(); //keys

	m_music.openFromFile("game music.ogg");
	m_music.setVolume(50);
	m_music.setLoop(true);

}

void Menu::show_menu()
{

	sf::RenderWindow m_wind(sf::VideoMode(900, 500), "menu");
	m_wind.clear(sf::Color::White);

	m_music.play();

	while (m_wind.isOpen())
	{
		m_wind.draw(m_background);

		//func draw button
		for (int i = 0; i < NUM_OF_BUTTONS; i++)
		{
			m_wind.draw(m_button[i]);
		}
		//end func

		m_wind.display();

		if (auto event = sf::Event(); m_wind.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_wind.close();
				//exit(EXIT_SUCCESS);
				break;

			case sf::Event::MouseButtonReleased:
			{
				int option = handle_click(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));

				switch (option)
				{
				case 0:
					m_controller.run();
					return;
				case 1:
					show_help();
					break;
				case 2:
					m_wind.close();
					//exit(EXIT_SUCCESS);
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
	m_background.setTexture(*Resources::getBackground(1));
	m_wind.draw(m_background);
	m_background.setTexture(*Resources::getBackground(0));
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
	for (int i = 0; i < NUM_OF_BUTTONS; i++)
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
	m_text.setFont(*Resources::getFont());

	m_data.setTexture(*Resources::getDataTexure(num_of_data));
	m_data.setPosition(sf::Vector2f(10, 50 + 100 * num_of_data));

	m_text.setPosition(m_data.getPosition());

	num_of_data++;
}
