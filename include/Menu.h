#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"



class Menu {
public:
	Menu();
	void show_menu();
	int handle_click(sf::Vector2f);

private:
	 
	sf::Text m_text;
	sf::RectangleShape m_button[3];
	sf::Sprite m_background;
	sf::RenderWindow m_wind;
	
};