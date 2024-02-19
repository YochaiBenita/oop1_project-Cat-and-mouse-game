#pragma once
#include <SFML/Graphics.hpp>

class Object 
{
public:
	Object();
	virtual ~Object();
	virtual void draw(sf::RenderWindow&) = 0;
private:
	sf::Sprite m_sp;
};