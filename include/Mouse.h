#pragma once
#include <SFML/Graphics.hpp>
#include "Moving_object.h"

class Mouse:public Moving_object {
public:
	Mouse(int, int);
	virtual ~Mouse();
	virtual void draw(sf::RenderWindow&);
	void move(float);

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
	sf::Vector2f m_diraction = sf::Vector2f(0.f,0.f);
	float speedForSeconds = 20;
};