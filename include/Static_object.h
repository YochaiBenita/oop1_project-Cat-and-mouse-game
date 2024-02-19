#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"
class Static_object :public Object {
public:
	Static_object(object_code, int, int);
	virtual ~Static_object();

	virtual void draw(sf::RenderWindow&)=0;
	void move(sf::Vector2f) {};

private:

};