#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"

class Static_object :public Object {
public:
	Static_object(object_code, int, int);
	Static_object() = default;
	virtual ~Static_object();

	virtual void draw(sf::RenderWindow&);
	virtual void move(sf::Vector2f) {};

	//virtual void handleCollision(Object&) = 0;
	virtual void handleCollision(Mouse&) {};//=0
	virtual void handleCollision(Cat&) {};//=0
	virtual void handleCollision(Cheese&) {};
	virtual void handleCollision(Door&) {};
	virtual void handleCollision(Gfreeze&) {};
	virtual void handleCollision(Gift&) {};
	virtual void handleCollision(Glife&) {};
	virtual void handleCollision(Gtime&) {};
	virtual void handleCollision(Key&) {};
	virtual void handleCollision(Wall&) {};

private:

};