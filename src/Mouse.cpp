#include "Mouse.h"

Mouse::Mouse(int col, int row) : Moving_object(mouse_t, col, row) {
}

Mouse::~Mouse() {

}

//void Mouse::draw(sf::RenderWindow&) {
//
//}

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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_diraction = sf::Vector2f(0.f, 0.f);
	}

	Moving_object::move(m_diraction * seconds * speedForSeconds);
}