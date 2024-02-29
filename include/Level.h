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

class Static_object;

struct Data {
	Data();
	sf::Sprite m_data;
	sf::Text m_text;

	static int num_of_data;
};


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
	void add_to_time(int);
	int num_of_moving();
	void pop_moving();
	int original_cats();
	void draw_data(sf::RenderWindow&);
	void freeze_gift(bool);
	float get_timer() const;
	void add_to_score(int);
	int get_level_score() const;

private:
	static int m_keys;
	bool m_exit = false;

	int m_hight = 0;
	int m_width = 0;
	int m_cats = 0;
	int m_level_score = 0;

	sf::RectangleShape m_background;
	sf::RectangleShape m_background_data;
	sf::Clock m_clock;

	float m_timer;
	float m_freezing_timer;

	static Data m_data[NUM_OF_DATA_TEXTURES];

	std::vector <std::unique_ptr<Moving_object>> m_movings;
	std::vector <std::unique_ptr<Static_object>> m_statics;

	std::unique_ptr <Moving_object> new_moving(char, int, int);
	std::unique_ptr <Static_object> new_static(char, int, int);
	
	bool handleCollision(Moving_object& obj);
};



