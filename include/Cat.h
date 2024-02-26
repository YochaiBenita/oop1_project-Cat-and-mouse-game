#pragma once
#include <SFML/Graphics.hpp>
#include "Moving_object.h"

class Cat :public Moving_object {
public:
	Cat(int, int);
	virtual ~Cat();
	//virtual void draw(sf::RenderWindow&);
	//virtual void set_direction();
	void move(float);

	virtual bool collision(Object&) ;
	virtual bool collision(Mouse&);
	//virtual bool collision(Cat&);
	//virtual bool collision(Cheese&) ;
	//virtual bool collision(Door&) ;
	//virtual bool collision(Gfreeze&) ;
	//virtual bool collision(Gift&) ;
	//virtual bool collision(Gkill&) ;
	//virtual bool collision(Glife&) ;
	//virtual bool collision(Gtime&) ;
	//virtual bool collision(Key&) ;

private:
	sf::Vector2f m_diraction = sf::Vector2f(0.f, 0.f);
	float speedForSeconds = 30;

	sf::Vector2f choose_diraction();
};