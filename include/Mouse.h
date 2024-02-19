#pragma once
#include <SFML/Graphics.hpp>
#include "Moving_object.h"

class Mouse:public Moving_object {
public:
	Mouse();
	virtual ~Mouse();
	virtual void draw(sf::RenderWindow&);
	virtual void move();

private:

};