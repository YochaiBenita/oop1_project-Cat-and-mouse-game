#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
//#include "Resources.h"

class Gkill :public Gift
{
public:
	Gkill(int, int);
	virtual ~Gkill() = default;

	virtual bool collision(Object&);
	virtual bool collision(Cat&);
	virtual bool collision(Mouse&);

private:

};
