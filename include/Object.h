#pragma once
#include <SFML/Graphics.hpp>

const auto TOPLEFT = sf::Vector2f (0.f, 0.f);
const float IMAGESIZE = 30.f;


class Object 
{
public:
	Object(const sf::Texture&, int, int);
	virtual ~Object();
	virtual void draw(sf::RenderWindow&);
	void set_position(sf::Vector2f);
	sf::Vector2f get_position() const;
	void move(sf::Vector2f);

private:
	sf::Sprite m_sp;
};