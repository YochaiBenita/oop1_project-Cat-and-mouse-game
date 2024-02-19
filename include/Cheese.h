#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"

class Cheese:public Static_object
{
public:
	Cheese(int, int);
	virtual ~Cheese();
	virtual void draw(sf::RenderWindow&)const override;

private:

};