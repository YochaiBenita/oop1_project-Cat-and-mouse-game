#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
//#include "Resources.h"

class Glife :public Gift
{
public:
	Glife(int, int);
	virtual ~Glife() = default;

	virtual bool collision(Object&);
	virtual bool collision(Cat&);
	virtual bool collision(Mouse&);
	virtual void open_gift();

private:

};