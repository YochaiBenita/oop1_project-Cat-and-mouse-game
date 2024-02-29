#pragma once
#include <SFML/Graphics.hpp>
#include "Moving_object.h"

class Mouse:public Moving_object {
public:
	using Moving_object::collision;

	Mouse(int, int);
	virtual ~Mouse();
	void move(float, Moving_object*);
	

	virtual bool collision(Object&)	override;
	virtual bool collision(Mouse&)	override;
	virtual bool collision(Cat&)	override;
	virtual bool collision(Cheese&)	override;
	virtual bool collision(Door&)	override;
	virtual bool collision(Gift&)	override;
	virtual bool collision(Key&)	override;
	
private:
	sf::Vector2f m_diraction = sf::Vector2f(0.f,0.f);
	sf::Sound m_currSound;

	void play_sound(const sf::SoundBuffer*);

};