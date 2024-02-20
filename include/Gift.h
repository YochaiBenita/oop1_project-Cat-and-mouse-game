#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
#include "Cat.h" //לבדוק מעגליות
#include "Mouse.h"//לבדוק מעגליות
#include "Resources.h"

class Gift :public Static_object
{
public:
	Gift(int col, int row) : Static_object(gift, col, row) {};
	virtual ~Gift();

	void handleCollision(Object& obj) { obj.handleCollision(*this); }
	void handleCollision(Cat& catPlayer) { catPlayer.handleCollision(*this); }
	void handleCollision(Mouse& mousePlayer) { mousePlayer.handleCollision(*this); }

private:

};