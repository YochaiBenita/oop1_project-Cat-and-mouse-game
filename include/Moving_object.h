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


	virtual bool collision(Object&)	{}
	virtual bool collision(Mouse&)	{}
	virtual bool collision(Cat&)	{}
	virtual bool collision(Cheese&)	{}
	virtual bool collision(Door&);
	virtual bool collision(Gfreeze&){}
	virtual bool collision(Gift&)	{}
	virtual bool collision(Glife&)	{}
	virtual bool collision(Gtime&)	{}
	virtual bool collision(Gkill&)	{}
	virtual bool collision(Key&)	{}
	virtual bool collision(Wall&);

private:
	sf::Vector2f m_original_loc;
	sf::Vector2f m_previous_loc;
};