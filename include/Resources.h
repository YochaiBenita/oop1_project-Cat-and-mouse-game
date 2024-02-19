#pragma once
#include <SFML/Graphics.hpp>
#include <string>

const int NUM_OF_TEXTURES = 10;
const int NUM_OF_SOUNDES = 10;
const int NUM_OF_FONTS = 10;

class Resources
{
public:
	Resources();
private:
	sf::Texture m_texures[NUM_OF_TEXTURES];
	sf::Font m_fonts[NUM_OF_SOUNDES];
	//sf::sound[];

};