#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include "Resources.h"

struct Data {
	Data();
	sf::Sprite m_data;
	sf::Text m_text;
	int* src;
	static int num_of_data;

	void update_data();
};


class Menu {
public:
	Menu();
	void show_menu(); 
	void show_help();
	void draw_data(sf::RenderWindow&);
	int handle_click(sf::Vector2f);

private:
	 
	//sf::Text m_text;
	sf::RectangleShape m_button[3];
	sf::Sprite m_background;
	sf::RenderWindow m_wind;

	Data m_data[4];
	
};