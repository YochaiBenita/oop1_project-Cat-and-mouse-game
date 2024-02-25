#pragma once
#include <SFML/Graphics.hpp>


const auto TOPLEFT = sf::Vector2f (0.f, 0.f);
const float IMAGESIZE = 30.f;

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

	virtual void collision(Object&) = 0;
	virtual void collision(Mouse&) = 0;
	virtual void collision(Cat&) = 0;
	virtual void collision(Cheese&) = 0;
	virtual void collision(Door&) = 0;
	virtual void collision(Gfreeze&) = 0;
	virtual void collision(Gift&) = 0;
	virtual void collision(Glife&) = 0;
	virtual void collision(Gkill&) = 0;
	virtual void collision(Gtime&) = 0;
	virtual void collision(Key&) = 0;
	virtual void collision(Wall&) = 0;

	virtual void draw(sf::RenderWindow&);
	void set_position(sf::Vector2f);
	sf::Vector2f get_position() const;
	virtual void move(sf::Vector2f);

private:
	sf::Sprite m_sp;
};