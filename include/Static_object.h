#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"

class Static_object :public Object {
public:
	Static_object(object_code, int, int);
	Static_object() = default;
	virtual ~Static_object();

	//virtual void draw(sf::RenderWindow&);
	//virtual void move(sf::Vector2f) {};

	virtual void collision(Object&) = 0;
	virtual void collision(Mouse&) = 0;
	virtual void collision(Cat&) = 0;
	virtual void collision(Cheese&) {};
	virtual void collision(Door&) {};
	virtual void collision(Gfreeze&) {};
	virtual void collision(Gift&) {};
	virtual void collision(Glife&) {};
	virtual void collision(Gtime&) {};
	virtual void collision(Key&) {};
	virtual void collision(Wall&) {};

private:

};