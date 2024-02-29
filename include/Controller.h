#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Level.h"
#include "Resources.h"


class Controller {
public:
	Controller();
	~Controller();
	void run(sf::RenderWindow&);
	static void add_score(int);
	static int get_life();
	static int get_score();
	static int get_level_num();
	void reset_controller();
	void summerry_print(sf::RenderWindow&, bool);

	static void freeze_gift();
	static void life_gift();
	static void kill_gift();
	static void time_gift();
	void play_sound(sf::SoundBuffer*);
	
 
private:
	static int m_life;
	static int m_score;
	static int m_levelNumber;
	bool m_to_exit = false;	

	static Level* m_currLevel;

	sf::Sound m_curr_sound;
};