#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"

class Moving_object :public Object {
public:
	Moving_object(object_code, int, int);
	virtual ~Moving_object();
	//virtual void draw(sf::RenderWindow&);
	virtual void move(float) {};//=0
	//virtual void set_direction()=0;
	void reset_location();
	virtual void move(sf::Vector2f);



	virtual void collision(Object&) = 0;
	virtual void collision(Mouse&) = 0;
	virtual void collision(Cat&) = 0;
	virtual void collision(Cheese&) = 0;
	virtual void collision(Door&) = 0;
	virtual void collision(Gfreeze&) = 0;;
	virtual void collision(Gift&) = 0;
	virtual void collision(Glife&) = 0;
	virtual void collision(Gtime&) = 0;
	virtual void collision(Gkill&) = 0;
	virtual void collision(Key&) = 0;
	virtual void collision(Wall&);

private:
	sf::Vector2f m_original_loc;
};