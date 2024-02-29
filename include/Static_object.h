#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Resources.h"


class Static_object :public Object {
public:
	Static_object(object_code, int, int);
	Static_object(object_code, object_code, int, int);
	Static_object() = default;
	virtual ~Static_object();

	virtual bool collision(Object&) = 0;
	virtual bool collision(Mouse&) = 0;
	virtual bool collision(Cat&) = 0;

};