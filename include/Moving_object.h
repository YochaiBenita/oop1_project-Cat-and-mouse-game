#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"

class Moving_object :public Object {
public:
	Moving_object(object_code, int, int);
	virtual ~Moving_object();
	virtual void draw(sf::RenderWindow&);
	virtual void move(float) = 0;
	void reset_location();
	virtual void move(sf::Vector2f);

private:
	sf::Vector2f m_original_loc;
};