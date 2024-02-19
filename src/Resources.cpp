#include "Resources.h"
#include <SFML/Graphics.hpp>

Resources::Resources()
{
	auto line = std::string();
	auto file = std::ifstream('texuters_names.txt');
	int i = 0;

	while (std::getline(file, line)) 
	{
		m_texures[i].loadFromFile(line);
		i++;
	}
	

}