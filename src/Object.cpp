#include "Object.h"

Object::Object(const sf::Texture& txtr, int col, int row) 
{
	m_sp.setTexture(txtr);
	
	auto v2p = sf::Vector2f(col, row);
	v2p.x += TOPLEFT.x;
	v2p.y += TOPLEFT.y;
	v2p *= IMAGESIZE;

	m_sp.setPosition(v2p);
	
}
Object::~Object() {

}

void Object::draw(sf::RenderWindow& window)
{
	window.draw(m_sp);
}
