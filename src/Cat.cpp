#pragma once
#include "Cat.h"
#include <iostream>
#include <cmath>

Cat::Cat(int col, int row) : Moving_object (cat_t, col, row) 
{}

Cat::~Cat() {}


void Cat::move(float seconds, Moving_object* mouse)
{
	if (!freeze_status())
	{
		auto catloc = this->get_position();
		auto mouseloc = mouse->get_position();

		float Dx = (mouseloc.x - catloc.x);
		float Dy = (mouseloc.y - catloc.y);

		if (abs(Dx) > abs(Dy))
		{
			m_diraction = (Dx > 0) ? sf::Vector2f(1, 0) : sf::Vector2f(-1, 0);
		}
		else
		{
			m_diraction = (Dy > 0) ? sf::Vector2f(0, 1) : sf::Vector2f(0, -1);
		}

		//m_diraction = choose_diraction();
		set_prev_loc(get_position());
		Object::move(m_diraction * speedForSeconds * seconds);
	}
}

bool Cat::collision(Object& obj)
{
	return obj.collision(*this);
	
}

bool Cat::collision(Mouse&)
{
	play_sound();
	///איזה לוזר
	return true;
}

bool Cat::collision(Cat&)
{
	set_position(get_previous_loc());

	return false;
}

//bool Cat::collision(Wall&)
//{
//	set_position(get_previous_loc());
//
//	return false;
//}

sf::Vector2f Cat::choose_diraction()
{
	switch (rand() % 4) {
	case 0:
		return sf::Vector2f(-1.f, 0.f);
	case 1:
		return sf::Vector2f(1.f, 0.f);
	case 2:
		return sf::Vector2f(0.f, -1.f);
	case 3:
		return sf::Vector2f(0.f, 1.f);
	}
	return sf::Vector2f(0.f, 1.f);//stam
}


