#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Level.h"
#include "Resources.h"
//#include "Menu.h"

class Controller {
public:
	Controller();
	~Controller();
	void run();
	//static sf::Texture* getTexutre(int);
	//static sf::Texture* getBackground(int);
	//static sf::Texture* getDataTexure(int);
	//static sf::SoundBuffer* getSoundBuffer(int);
	static void add_score(int);
	//static sf::Font* getFont();
	//static void draw_data(sf::RenderWindow&);
	static int get_life();
	static int get_score();
	//int* get_timer_ptr();
	void reset_controller();

	static void freeze_gift();
	static void life_gift();
	static void kill_gift();
	static void time_gift();
	
 
private:
	static int m_life;
	static int m_score;
	int m_levelNumber = 0;
	bool m_to_exit = false;
	//static Menu m_menu;
	

	//static sf::Text m_text;
	//static sf::Sprite m_dataSP[3];
	static Level* m_currLevel;

	//static Level* m_currLevel;
	//static Resources m_resources;


	//const std::vector<std::string> m_levels_name;
	//const sf::Texture* m_texures;
};