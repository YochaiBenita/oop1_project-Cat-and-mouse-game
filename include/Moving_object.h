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
	void set_prev_loc(sf::Vector2f);
	sf::Vector2f get_previous_loc()const;


	virtual bool collision(Object&) =0;// { return false; }
	virtual bool collision(Mouse&) =0;//	{ return false; }
	virtual bool collision(Cat&) =0;// { return false; }
	virtual bool collision(Cheese&)	{ return false; }
	virtual bool collision(Door&);
	//virtual bool collision(Gfreeze&){ return false; }
	virtual bool collision(Gift&)	{ return false; }
	//virtual bool collision(Glife&)	{ return false; }
	//virtual bool collision(Gtime&)	{ return false; }
	//virtual bool collision(Gkill&)	{ return false; }
	virtual bool collision(Key&)	{ return false; }
	virtual bool collision(Wall&) =0;

private:
	sf::Vector2f m_original_loc;
	sf::Vector2f m_previous_loc;
};