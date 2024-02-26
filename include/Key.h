#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
//#include "Resources.h"

class Key :public Static_object
{
public:
	Key(int col, int row);
	//virtual ~Key() = default;

	virtual bool collision(Object& obj);
	virtual bool collision(Cat& catPlayer);
	virtual bool collision(Mouse& mousePlayer);

	//virtual void to_delete() {m_to_delete = true;}
private:

};