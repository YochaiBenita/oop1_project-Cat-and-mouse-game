#pragma once
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include "Moving_object.h"
#include "Static_object.h"
#include "Cat.h"
#include "Mouse.h"
#include "Cheese.h"
#include "Door.h"
#include "Gift.h"
#include "Gfreeze.h"
#include "Gkill.h"
#include "Gtime.h"
#include "Glife.h"
#include "Key.h"
#include "Wall.h"
#include <iostream>
#include <string>

//#include "Controller.h"//מייצר אינקלוד מעגלי

class Static_object;

class Level{
public:
	Level(std::string fileName);
	bool play();
	void reset_level();
	bool to_exit() const;
	static void add_key();
	static void use_key();
	static int get_keys();
	void check_move(Moving_object&);
	void play_sound(sf::SoundBuffer&);
	static int* get_timer_ptr();
	void add_to_time(int);
	int num_of_moving();
	void pop_moving();

private:
	static int m_keys;
	int m_num_of_cheeses = 0; //check
	bool m_exit = false;
	int m_hight = 0;
	int m_width = 0;
	int m_time = 0;
	
	sf::RectangleShape m_background;
	sf::Clock m_clock;
	///sf::Time m_timer;
	float m_timer;
	static int m_int_timer;
	std::string m_timerString;


	std::vector <std::unique_ptr<Moving_object>> m_movings;
	std::vector <std::unique_ptr<Static_object>> m_statics;

	std::unique_ptr <Moving_object> new_moving(char, int, int);
	std::unique_ptr <Static_object> new_static(char, int, int);
	
	bool handleCollision(Moving_object& obj);
	//void timer();
};



