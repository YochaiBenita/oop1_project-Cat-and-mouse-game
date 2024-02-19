#pragma once
#include <SFML/Graphics.hpp>



class Menu {
public:
	Menu();
	void show_menu();
private:
	sf::RenderWindow m_wind;
	sf::Text m_text;

};