#pragma once
#include <SFML/Graphics.hpp>
#include "Moving_object.h"

class Cat :public Moving_object {
public:
	Cat(int, int);
	virtual ~Cat();
	virtual void draw(sf::RenderWindow&);
	virtual void move();

private:

};