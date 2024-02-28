#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
//#include "Resources.h"

class Gtime :public Gift
{
public:
	Gtime(int, int);;
	virtual ~Gtime() = default;

	virtual bool collision(Object&);
	virtual bool collision(Cat&);
	virtual bool collision(Mouse&);

private:

};