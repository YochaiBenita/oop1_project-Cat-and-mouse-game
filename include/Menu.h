#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include "Resources.h"
#include "Controller.h"

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
	static void draw_data(sf::RenderWindow&);
	int handle_click(sf::Vector2f);

private:
	 
	sf::Sprite m_button[NUM_OF_BUTTONS];
	sf::Sprite m_background;
	sf::RenderWindow m_wind;
	sf::Music m_music;
	Controller m_controller;

	static Data m_data[NUM_OF_DATA_TEXTURES];
	
};