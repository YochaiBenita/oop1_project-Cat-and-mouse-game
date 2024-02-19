#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class Static_object :public Object {
public:
	Static_object();
	virtual ~Static_object();
	virtual void draw(sf::RenderWindow&);

private:

};