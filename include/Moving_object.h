#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class Moving_object :public Object {
public:
	Moving_object();
	virtual ~Moving_object();
	virtual void draw(sf::RenderWindow&) = 0;
	virtual void move() = 0;

private:

};