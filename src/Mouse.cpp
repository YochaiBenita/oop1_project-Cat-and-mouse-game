#pragma once
#include "Mouse.h"
#include "Key.h"
#include "Door.h"
#include "Cat.h"
#include "Cheese.h"
#include "Controller.h"
#include "Level.h"

Mouse::Mouse(int col, int row) : Moving_object(mouse_t, col, row) {
}

Mouse::~Mouse() {

}

void Mouse::move(float seconds, Moving_object* mouse)
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
	else 
	{
		m_diraction = sf::Vector2f(0.f, 0.f);
	}
	
	set_prev_loc(get_position());
	
	Object::move(m_diraction * seconds * SPEED_FOR_SEC_MOUSE);
}

bool Mouse::collision(Object& object)
{
	return object.collision(*this);
}

bool Mouse::collision(Mouse&)
{
	return false;
}

bool Mouse::collision(Cat& cat)
{
	return cat.collision(*this);
}


bool Mouse::collision(Cheese& cheese)
{
	play_sound(cheese.get_sound());
	Controller::add_score(SCORE_OF_CHEESE);
	return true;
}

bool Mouse::collision(Door& door)
{
	if (Level::get_keys() > 0)
	{
		play_sound(door.get_sound());
		Controller::add_score(SCORE_OF_DOOR);
		Level::use_key();

		return true;
	}
	set_position(get_previous_loc());
	return false;
}

bool Mouse::collision(Gift& gift)
{
	play_sound(gift.get_sound());
	gift.open_gift();
	Controller::add_score(SCORE_OF_GIFT);
	return true;
}


bool Mouse::collision(Key& key)
{
	play_sound(key.get_sound());
	Level::add_key();
	return true;
}

void Mouse::play_sound(const sf::SoundBuffer* sndBF)
{
	m_currSound.setBuffer(*sndBF);
	m_currSound.play();
}


