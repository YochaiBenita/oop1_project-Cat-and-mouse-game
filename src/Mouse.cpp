#pragma once
#include "Mouse.h"
#include "Key.h"
#include "Door.h"

Mouse::Mouse(int col, int row) : Moving_object(mouse_t, col, row) {
}

Mouse::~Mouse() {

}

void Mouse::move(float seconds) 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_diraction = sf::Vector2f(-1.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_diraction = sf::Vector2f(1.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_diraction = sf::Vector2f(0.f, -1.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_diraction = sf::Vector2f(0.f, 1.f);
	}
	else //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_diraction = sf::Vector2f(0.f, 0.f);
	}
	//שמירת מיקום ישן או משהו כזה
	Moving_object::move(m_diraction * seconds * speedForSeconds);
}

//void Mouse::set_direction()
//{
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//	{
//		m_diraction = sf::Vector2f(-1.f, 0.f);
//	}
//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//	{
//		m_diraction = sf::Vector2f(1.f, 0.f);
//	}
//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//	{
//		m_diraction = sf::Vector2f(0.f, -1.f);
//	}
//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//	{
//		m_diraction = sf::Vector2f(0.f, 1.f);
//	}
//	else //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
//	{
//		m_diraction = sf::Vector2f(0.f, 0.f);
//	}
//}

//--------------------------------------------------------------------------
void Mouse::collision(Object& object)
{
	object.collision(*this);
}

void Mouse::collision(Cat& cat)
{
	cat.collision(*this);
}

void Mouse::collision(Cheese& cheese)
{
	cheese.to_delete();
	//score+
	Controller::add_score(SCORE_OF_CHEESE);
	
}

void Mouse::collision(Door& door)
{
	if (m_num_of_keys > 0)
	{
		door.to_delete();
		Controller::add_score(SCORE_OF_DOOR);
		m_num_of_keys--;
	}
	door.collision(*this);
}

void Mouse::collision(Gfreeze& gift)
{
	gift.collision(*this);
}

void Mouse::collision(Gift& gift)
{
	gift.collision(*this);
}

void Mouse::collision(Glife& gift)
{
	gift.collision(*this);
}

void Mouse::collision(Gkill& gift)
{
	gift.collision(*this);
}

void Mouse::collision(Gtime& gift)
{
	gift.collision(*this);
}

void Mouse::collision(Key& key)
{
	m_num_of_keys++;
	key.to_delete();
	//key.collision(*this);
}
