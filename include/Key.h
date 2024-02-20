#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
//#include "Resources.h"

class Key :public Static_object
{
public:
	Key(int col, int row) : Static_object(key_t, col, row) {};
	virtual ~Key() = default;

	//void handleCollision(Object& obj) { obj.handleCollision(*this); }
	virtual void handleCollision(Cat& catPlayer) { catPlayer.handleCollision(*this); }
	virtual void handleCollision(Mouse& mousePlayer) { mousePlayer.handleCollision(*this); }

private:

};