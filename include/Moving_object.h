#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"

class Moving_object :public Object {
public:
	

	Moving_object(object_code, int, int);
	virtual ~Moving_object();

	virtual void move(float, Moving_object*) = 0;
	void reset_location();
	void set_prev_loc(sf::Vector2f);
	sf::Vector2f get_previous_loc()const;
	bool freeze_status() const;
	virtual void set_freeze(bool);


	virtual bool collision(Object&) =0;
	virtual bool collision(Mouse&) =0;
	virtual bool collision(Cat&) =0;
	virtual bool collision(Cheese&)	{ return false; }
	virtual bool collision(Door&);
	virtual bool collision(Gift&) { return false; }
	virtual bool collision(Key&) { return false; }
	virtual bool collision(Wall&);

private:
	sf::Vector2f m_original_loc;
	sf::Vector2f m_previous_loc;
	bool m_freeze = false;
};