#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Resources.h"

class Mouse;
class Cat;
class Cheese;
class Door;
class Gfreeze;
class Gift;
class Glife;
class Gkill;
class Gtime;
class Key;
class Wall;

class Object 
{
public:
	Object(const sf::Texture*, int, int);
	virtual ~Object();

	bool checkCollision(Object& obj) const;

	virtual bool collision(Object&) = 0;
	virtual bool collision(Mouse&) = 0;
	virtual bool collision(Cat&) = 0;

	virtual void draw(sf::RenderWindow&)const;
	void set_position(sf::Vector2f);
	sf::Vector2f get_position() const;
	virtual void move(sf::Vector2f);
	sf::Sprite get_sprite()const;
	void set_color(sf::Color);

private:
	sf::Sprite m_sp;

};