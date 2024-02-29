#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"

class Gkill :public Gift
{
public:
	Gkill(int, int);
	
	virtual void open_gift();
private:

};
