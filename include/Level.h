#pragma once
#include <vector>
#include <string>




class Level : public Controller
{
public:
	Level(std::string fileName);
	Level() = default;


private:
	std::vector<std::string> m_board;
};



