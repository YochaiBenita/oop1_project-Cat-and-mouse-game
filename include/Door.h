#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
#include "Cat.h"
#include "Mouse.h"

class Door :public Static_object
{
public:
	Door(int col, int row):Static_object();
	virtual ~Door();
	virtual void draw(sf::RenderWindow&)const override;

	void handleCollision(Object& obj) { obj.handleCollision(*this); }
	void handleCollision(Cat& cat) { cat.handleCollision(*this); }
	void handleCollision(Mouse& mouse) { mouse.handleCollision(*this); }

private:

};