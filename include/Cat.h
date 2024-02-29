#pragma once
#include <SFML/Graphics.hpp>
#include "Moving_object.h"

class Cat :public Moving_object {
public:
	using Moving_object::collision;

	Cat(int, int);
	virtual ~Cat();

	void move(float, Moving_object*);

	virtual bool collision(Object&)	override;
	virtual bool collision(Mouse&)	override;
	virtual bool collision(Cat&)	override; 

private:
	sf::Vector2f m_diraction = sf::Vector2f(0.f, 0.f);
	sf::Vector2f choose_diraction();
};