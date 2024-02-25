#pragma once
#include "Cheese.h"

Cheese::Cheese(int col, int row) : Static_object(cheese_t, col, row) 
{
	m_count++;
}
Cheese::~Cheese()
{
	m_count--;
}
;

void Cheese::collision(Object& obj)
{
	obj.collision(*this);
}

void Cheese::collision(Cat& catPlayer)
{
	catPlayer.collision(*this);
}

void Cheese::collision(Mouse& mousePlayer)
{
	mousePlayer.collision(*this);
}