#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class Moving_object :public Object {
public:
	Moving_object(object_code, int, int);
	virtual ~Moving_object();
	virtual void draw(sf::RenderWindow&) = 0;
	virtual void move() = 0;
	void reset_location();

private:
	sf::Vector2f m_original_loc;
};