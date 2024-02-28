#pragma once
#include <SFML/Graphics.hpp>
#include "Moving_object.h"

class Cat :public Moving_object {
public:
	using Moving_object::collision;

	Cat(int, int);
	virtual ~Cat();
	//virtual void draw(sf::RenderWindow&);
	//virtual void set_direction();
	void move(float, Moving_object*);

	virtual bool collision(Object&)	override;
	virtual bool collision(Mouse&)	override;
	virtual bool collision(Cat&)	override;  //mybe later
	//virtual bool collision(Cheese&) ;
	//virtual bool collision(Door&) ;
	//virtual bool collision(Gfreeze&) ;
	//virtual bool collision(Gift&) ;
	//virtual bool collision(Gkill&) ;
	//virtual bool collision(Glife&) ;
	//virtual bool collision(Gtime&) ;
	//virtual bool collision(Key&) ;
	//virtual bool collision(Wall&);

private:
	sf::Vector2f m_diraction = sf::Vector2f(0.f, 0.f);
	

	sf::Vector2f choose_diraction();
};