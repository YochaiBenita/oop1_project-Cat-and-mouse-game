#pragma once
#include <SFML/Graphics.hpp>
#include "Moving_object.h"
//#include "Controller.h";
#include "Cheese.h"

class Mouse:public Moving_object {
public:
	Mouse(int, int);
	virtual ~Mouse();
	//virtual void draw(sf::RenderWindow&);
	//virtual void set_direction();
	void move(float);


	virtual void collision(Object&);
	//virtual void collision(Mouse&);
	virtual void collision(Cat&);
	virtual void collision(Cheese&);
	virtual void collision(Door&);
	virtual void collision(Gfreeze&);
	virtual void collision(Gift&);
	virtual void collision(Glife&);
	virtual void collision(Gkill&);
	virtual void collision(Gtime&);
	virtual void collision(Key&);

private:
	sf::Vector2f m_diraction = sf::Vector2f(0.f,0.f);
	float speedForSeconds = 20;
	int m_num_of_keys = 0;
};