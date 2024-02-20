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
class Gtime;
class Key;
class Wall;

class Object 
{
public:
	Object(const sf::Texture*, int, int);
	virtual ~Object();

	//virtual void handleCollision(Object&) = 0;
	virtual void handleCollision(Mouse&) = 0;
	virtual void handleCollision(Cat&) = 0;
	virtual void handleCollision(Cheese&) = 0;
	virtual void handleCollision(Door&) = 0;
	virtual void handleCollision(Gfreeze&) = 0;
	virtual void handleCollision(Gift&) = 0;
	virtual void handleCollision(Glife&) = 0;
	virtual void handleCollision(Gtime&) = 0;
	virtual void handleCollision(Key&) = 0;
	virtual void handleCollision(Wall&) = 0;

	virtual void draw(sf::RenderWindow&);
	void set_position(sf::Vector2f);
	sf::Vector2f get_position() const;
	virtual void move(sf::Vector2f);

private:
	sf::Sprite m_sp;
};