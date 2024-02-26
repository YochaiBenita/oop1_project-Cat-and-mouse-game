#pragma once
#include "Cheese.h"
#include "Mouse.h"
#include "Cat.h"

Cheese::Cheese(int col, int row) : Static_object(cheese_t, col, row) 
{
	m_count++;
}
Cheese::~Cheese()
{
	m_count--;
}
;

bool Cheese::collision(Object& obj)
{
	return obj.collision(*this);
}

bool Cheese::collision(Cat& catPlayer)
{
	return catPlayer.collision(*this);
}

bool Cheese::collision(Mouse& mousePlayer)
{
	return mousePlayer.collision(*this);
}

//void Cheese::to_delete()
//{
//	m_to_delete = true;
//}
