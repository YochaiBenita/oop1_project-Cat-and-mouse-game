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
#include "Key.h"
#include "Wall.h"
#include <iostream>
//#include "Controller.h"//מייצר אינקלוד מעגלי

class Static_object;

class Level{
public:
	Level(std::string fileName);
	bool play();
	void reset_locations();
	bool to_exit() const;

private:
	int m_keys = 0;
	int m_num_of_cheeses = 0;
	bool m_exit = false;
	int m_hight = 0;
	int m_width = 0;

	std::vector <std::unique_ptr<Moving_object>> m_movings;
	std::vector <std::unique_ptr<Static_object>> m_statics;

	std::unique_ptr <Moving_object> new_moving(char, int, int);
	std::unique_ptr <Static_object> new_static(char, int, int);
	
	bool handleCollision(Moving_object& obj);
};



