#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"

class Moving_object :public Object {
public:
	Moving_object(object_code, int, int);
	virtual ~Moving_object();
	//virtual void draw(sf::RenderWindow&);
	virtual void move(float) {};//=0
	void reset_location();
	virtual void move(sf::Vector2f);

	//virtual void handleCollision(Object&) = 0;
	virtual void handleCollision(Mouse&) {};
	virtual void handleCollision(Cat&) {};
	virtual void handleCollision(Cheese&) {};
	virtual void handleCollision(Door&) {};
	virtual void handleCollision(Gfreeze&) {};
	virtual void handleCollision(Gift&) {};
	virtual void handleCollision(Glife&) {};
	virtual void handleCollision(Gtime&) {};
	virtual void handleCollision(Key&) {};
	virtual void handleCollision(Wall&) {};

private:
	sf::Vector2f m_original_loc;
};