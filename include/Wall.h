#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
//#include "Resources.h"
class Moving_object;

class Wall :public Static_object
{
public:
	Wall(int col, int row);
	//virtual ~Wall() = default;

	virtual bool collision(Object& obj);
	//virtual bool collision(Moving_object& obj);

	virtual bool collision(Cat& catPlayer);// { return false; };
	virtual bool collision(Mouse& mousePlayer);// { return false; };

private:

};