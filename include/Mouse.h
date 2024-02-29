#pragma once
#include <SFML/Graphics.hpp>
#include "Moving_object.h"
//#include "Controller.h";


class Mouse:public Moving_object {
public:
	using Moving_object::collision;

	Mouse(int, int);
	virtual ~Mouse();
	//virtual void draw(sf::RenderWindow&);
	//virtual void set_direction();
	void move(float, Moving_object*);
	

	virtual bool collision(Object&)	override;
	virtual bool collision(Mouse&)	override;
	virtual bool collision(Cat&)	override;
	virtual bool collision(Cheese&)	override;
	virtual bool collision(Door&)	override;
	//virtual bool collision(Gfreeze&);
	virtual bool collision(Gift&)	override;
	//virtual bool collision(Glife&);
	//virtual bool collision(Gkill&);
	//virtual bool collision(Gtime&);
	virtual bool collision(Key&)	override;
	//virtual bool collision(Wall&);
	void play_sound(const sf::SoundBuffer*);
	//void set_freeze(bool status) override { };

private:
	sf::Vector2f m_diraction = sf::Vector2f(0.f,0.f);
	sf::Sound m_currSound;
	//int m_num_of_keys = 0;
};