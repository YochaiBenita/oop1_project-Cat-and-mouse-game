#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
#include "Resources.h"

class Key :public Static_object
{
public:
	Key(int col, int row) : Static_object(key, col, row) {};
	virtual ~Key();

	//void handleCollision(Object& obj) { obj.handleCollision(*this); }
	void handleCollision(Cat& catPlayer) { catPlayer.handleCollision(*this); }
	void handleCollision(Mouse& mousePlayer) { mousePlayer.handleCollision(*this); }

private:

};