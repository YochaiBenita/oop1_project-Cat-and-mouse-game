#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"

class Glife :public Gift
{
public:
	Glife(int, int);

	virtual void open_gift();

private:

};