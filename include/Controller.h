#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Level.h"

const int NUM_OF_TXTR = 7;
const std::string FileNames[NUM_OF_TXTR] = {
	"mouse.png",
	"cat.png",
	"chease.png",
	"door.png",
	"gift.png",
	"key.png",
	"wall.png",
};

class Controller {
public:
	Controller();
	~Controller();
	void run();

	

private:
	int m_life = 3;
	int m_score = 0;
	int m_levelNumber = 0;
	bool m_to_exit = false;

	Level* m_currLevel;
	const std::vector<std::string> m_levels_name;
	const sf::Texture* m_texures;
};