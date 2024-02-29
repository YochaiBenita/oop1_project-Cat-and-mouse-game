#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"

class Cheese :public Static_object
{
public:
	Cheese(int, int);
	virtual ~Cheese();

	static int get_cheese_num();
	static void reset_cheese_counter();

	virtual bool collision(Object&);
	virtual bool collision(Cat&);
	virtual bool collision(Mouse&);


private:
	static int m_count;
};