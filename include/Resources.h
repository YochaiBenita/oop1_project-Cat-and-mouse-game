#pragma once
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include <fstream>
#include <string>


const int NUM_OF_TEXTURES = 7;

enum object_code {
	mouse_t, cat_t, cheese_t,
	door_t, gift_t, key_t, wall_t,
	Gfreeze_t, Glife_t, Gtime_t, Gkill_t
};



//const int NUM_OF_SOUNDES = 10;
//const int NUM_OF_FONTS = 10;

class Resources
{
public:
	Resources();
	sf::Texture* getTextureAt(int);
	sf::Texture* getBackground(int);
	// get sound at
	std::string getLevelNameAt(int) const;
	int numOfLevels() const;

private:
	sf::Texture m_texures[NUM_OF_TEXTURES];
	sf::Texture m_backgroungs[2];
	//sf::Font m_fonts[NUM_OF_SOUNDES];
	std::vector<std::string> m_levels_name;
	//sf::SoundBuffer[];

	std::string m_FileNames[NUM_OF_TEXTURES] = {
	"mouse.png",
	"cat.png",
	"cheese.png",
	"door.png",
	"gift.png",
	"key.png",
	"wall.png"
	};

};