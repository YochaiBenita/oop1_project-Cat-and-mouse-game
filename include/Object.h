#pragma once
#include <SFML/Graphics.hpp>

const auto TOPLEFT = sf::Vector2f (0.f, 0.f);
const float IMAGESIZE = 30.f;

enum object_code {
	mouse, cat, chease,
	door, gift, key, wall
};


class Object 
{
public:
	Object(const sf::Texture&, int, int);
	virtual ~Object();
	virtual void draw(sf::RenderWindow&);
private:
	sf::Sprite m_sp;
};