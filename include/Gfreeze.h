#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"

class Gfreeze :public Gift
{
public:
	Gfreeze(int, int);

	virtual void open_gift();

};