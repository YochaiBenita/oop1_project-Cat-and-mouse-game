#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
#include "Cat.h"
#include "Mouse.h"

const int SCORE_OF_GIFT = 5;

class Gift : public Static_object
{
public:
	Gift(object_code obj, int col, int row);
	virtual ~Gift() = default;
	virtual void open_gift() = 0;
	virtual bool collision(Object&);
	virtual bool collision(Cat&);
	virtual bool collision(Mouse&);

	//virtual void 
};