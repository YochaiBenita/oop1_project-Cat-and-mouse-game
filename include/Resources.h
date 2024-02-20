#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <string>


const int NUM_OF_TXTR = 7;

enum object_code {
	mouse, cat, cheese,
	door, gift, key, wall,
	freeze, life, time
};

const std::string FileNames[NUM_OF_TXTR] = {
	"mouse",
	"cat",
	"cheese",
	"door",
	"gift",
	"key",
	"wall"
};

const int NUM_OF_TEXTURES = 7;
//const int NUM_OF_SOUNDES = 10;
//const int NUM_OF_FONTS = 10;

class Resources
{
public:
	Resources();
	sf::Texture getTextureAt(int) const;
	// get sound at
	std::string getLevelNameAt(int) const;
	int numOfLevels() const;

private:
	sf::Texture m_texures[NUM_OF_TEXTURES];
	//sf::Font m_fonts[NUM_OF_SOUNDES];
	std::vector<std::string> m_levels_name;
	//sf::SoundBuffer[];

};