#include "Object.h"
#include <iostream>
#include "Controller.h"

Object::Object(const sf::Texture* txtr, int col, int row) :
	m_sp(*txtr)
{
	auto v2p = sf::Vector2f(col, row);
	v2p *= IMAGESIZE;
	v2p.x += TOPLEFT.x;
	v2p.y += TOPLEFT.y;

	m_sp.setPosition(v2p);

}

Object::~Object() {

}

bool Object::checkCollision(Object& obj) const
{
	if (&obj == this)
	{
		return false;
	}

	sf::FloatRect overlapRect;

	if (m_sp.getGlobalBounds().intersects(obj.m_sp.getGlobalBounds(), overlapRect))
	{
		if (overlapRect.height > APPROVED_OVERLAP && overlapRect.width > APPROVED_OVERLAP)//�����!!!!
		{
			return true;
		}
	}

	return false;
}

void Object::draw(sf::RenderWindow& window)const
{
	window.draw(m_sp);
}

void Object::set_position(sf::Vector2f v2p)
{
	m_sp.setPosition(v2p);
}

sf::Vector2f Object::get_position() const
{
	return m_sp.getPosition();
}

void Object::move(sf::Vector2f v2d)
{
	m_sp.move(v2d);
}

sf::Sprite Object::get_sprite() const
{
	return m_sp;
}

void Object::set_color(sf::Color color)
{
	m_sp.setColor(color);
}
