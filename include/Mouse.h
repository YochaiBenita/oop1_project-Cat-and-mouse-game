#pragma once
#include <SFML/Graphics.hpp>
#include "Moving_object.h"

class Mouse:public Moving_object {
public:
	Mouse(int, int);
	virtual ~Mouse();
	virtual void draw(sf::RenderWindow&);
	void move(float);

private:
	sf::Vector2f m_diraction = sf::Vector2f(0.f,0.f);
	float speedForSeconds = 20;
};