#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
//#include "Resources.h"

class Gfreeze :public Gift
{
public:
	Gfreeze(int, int);
	virtual ~Gfreeze() = default;

	virtual bool collision(Object&);
	virtual bool collision(Cat&);
	virtual bool collision(Mouse&);
	virtual void open_gift();

private:

};