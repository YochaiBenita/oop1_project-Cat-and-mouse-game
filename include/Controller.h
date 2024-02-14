#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Level.h"


class Controller {
public:
	Controller();
	~Controller();
	Controller& operator=(const GameController&) = default;

private:
	int m_life = 3;
	int m_score = 0;
	int m_levelNumber = 0;

	Level* m_currLevel;
	const std::vector<std::string> m_levels_name;

	//void printValues() const;
};