#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include "Level.h"
#include "Resources.h"
#include "Menu.h"

class Controller {
public:
	Controller();
	~Controller();
	void run();
	static sf::Texture* getTexutre(int);
	static sf::Texture* getBackground(int);
	static sf::Texture* getDataTexure(int);
	static sf::SoundBuffer* getSoundBuffer(int);
	static void add_score(int);
	static sf::Font* getFont();
	static void draw_data(sf::RenderWindow&);
	int* get_live();
	static int* get_score();


private:
	int m_life = 3;
	static int m_score;
	int m_levelNumber = 0;
	bool m_to_exit = false;
	static Menu m_menu;
	sf::Music m_music;
	//static sf::Text m_text;
	//static sf::Sprite m_dataSP[3];


	static Level* m_currLevel;
	static Resources m_resources;


	//const std::vector<std::string> m_levels_name;
	//const sf::Texture* m_texures;
};