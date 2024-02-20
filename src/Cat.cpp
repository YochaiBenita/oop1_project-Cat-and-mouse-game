#include "Cat.h"
#include <iostream>

Cat::Cat(int col, int row) : Moving_object (cat_t, col, row) 
{
}

Cat::~Cat() {

}

void Cat::move(float seconds) {
	m_diraction = choose_diraction();

	Moving_object::move(m_diraction * speedForSeconds * seconds);
}

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
}
