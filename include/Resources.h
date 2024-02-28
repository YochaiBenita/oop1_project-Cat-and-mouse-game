#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <string>
 
const int NUM_OF_TEXTURES = 7;
const int NUM_OF_BACKGROUNDS = 3;
const auto TOPLEFT = sf::Vector2f(100.f, 0.f);
const float IMAGESIZE = 30.f;
const int NUM_OF_SOUNDES = 7;
//const int NUM_OF_FONTS = 10;



enum object_code {
	mouse_t, cat_t, cheese_t,
	door_t, gift_t, key_t, wall_t,
	Gfreeze_t, Glife_t, Gtime_t, Gkill_t
};


class Resources
{
public:
	Resources();
	static sf::Texture* getTextureAt(int);
	static sf::Texture* getDataTexure(int);
	static sf::Texture* getBackground(int);
	static sf::SoundBuffer* getSoundBuffer(int);

	static sf::Font* getFont();
	// get sound at
	static std::string getLevelNameAt(int);
	static int numOfLevels();

private:
	static sf::Texture m_texures[NUM_OF_TEXTURES];
	static sf::Texture m_data_texures[4];
	static sf::Texture m_backgroungs[NUM_OF_BACKGROUNDS];
	static sf::SoundBuffer m_sound_buffer[NUM_OF_SOUNDES];
	static sf::Font m_font;
	static std::vector<std::string> m_levels_name;

	std::string m_FileNames[NUM_OF_TEXTURES] = {
	"mouse.png",
	"cat.png",
	"cheese.png",
	"door.png",
	"gift.png",
	"key.png",
	"wall.png"
	};

	std::string m_BackgroundsNames[NUM_OF_BACKGROUNDS] = {
	"backgroundmenu.png",
	"help.png",
	"backgroundtile.png",
	};

	std::string m_DataTexturesNames[4] = {
	"clock-60.png",
	"heart.png",
	"star.png",
	"key.png"
	};

	std::string m_SoundNames[NUM_OF_SOUNDES] = {
	"success.ogg",
	"loss.ogg",
	"bite.ogg",
	"door open.ogg",
	"gift.ogg",
	"collect key.ogg",
	"door collision.ogg"	
	};
};