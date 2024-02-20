#pragma once
#include <SFML/Graphics.hpp>
#include "Moving_object.h"

class Cat :public Moving_object {
public:
	Cat(int, int);
	virtual ~Cat();
	virtual void draw(sf::RenderWindow&);
	void move(float);

private:
	sf::Vector2f m_diraction = sf::Vector2f(0.f, 0.f);
	float speedForSeconds = 20;

	sf::Vector2f choose_diraction();
};