#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"


class Static_object :public Object {
public:
	Static_object(object_code, int, int);
	Static_object() = default;
	virtual ~Static_object();

	//virtual void draw(sf::RenderWindow&);
	//virtual void move(sf::Vector2f) {};

	virtual bool collision(Object&) = 0;
	virtual bool collision(Mouse&) = 0;
	virtual bool collision(Cat&) = 0;
	//virtual bool collision(Cheese&) {};
	//virtual bool collision(Door&) {};
	//virtual bool collision(Gfreeze&) {};
	//virtual bool collision(Gift&) {};
	//virtual bool collision(Glife&) {};
	//virtual bool collision(Gtime&) {};
	//virtual bool collision(Key&) {};
	//virtual bool collision(Wall&) {};
	
	//virtual void to_delete() = 0;
	//bool to_erase();

protected:
	//bool m_to_delete = false;
};