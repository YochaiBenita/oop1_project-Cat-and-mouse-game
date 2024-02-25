#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
//#include "Resources.h"

class Cheese :public Static_object
{
public:
	Cheese(int, int);
	virtual ~Cheese();

	virtual void collision(Object&);
	virtual void collision(Cat&);//אולי לעשות רק למובינג אובגקט
	virtual void collision(Mouse&);

private:
	static int m_count;
};