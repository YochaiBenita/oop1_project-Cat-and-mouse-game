#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
//#include "Resources.h"

class Key :public Static_object
{
public:
	Key(int col, int row);
	//virtual ~Key() = default;

	virtual bool collision(Object&);
	virtual bool collision(Cat&);
	virtual bool collision(Mouse&);

	//virtual void to_delete() {m_to_delete = true;}
private:

};