#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include <string>
 
const int NUM_OF_TEXTURES = 11;
const int NUM_OF_BACKGROUNDS = 3;
const auto TOPLEFT = sf::Vector2f(100.f, 0.f);
const float IMAGESIZE = 30.f;
const int NUM_OF_DATA_TEXTURES = 4;
const int NUM_OF_SOUNDES = 7;
const int NUM_OF_BUTTONS = 3;
const int TIME_GIFT = 5;
const int SCORE_OF_GIFT = 5;
const int SCORE_OF_CHEESE = 10;
const int SCORE_OF_DOOR = 2;




enum object_code {
	mouse_t, cat_t, cheese_t,
	door_t, gift_t, key_t, wall_t,
	Gfreeze_t, Glife_t, Gtime_t, Gkill_t
};


class Resources
{
public:
	static Resources& getInstance();
	sf::Texture* getTextureAt(int);
	sf::Texture* getDataTexure(int);
	sf::Texture* getBackground(int);
	sf::SoundBuffer* getSoundBuffer(int);
	sf::Texture* getTextureButtons(int);
	sf::Font* getFont();
	// get sound at
	std::string getLevelNameAt(int);
	int numOfLevels();

private:
	Resources();
	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;
	sf::Texture m_texures[NUM_OF_TEXTURES];
	sf::Texture m_data_texures[NUM_OF_DATA_TEXTURES];
	sf::Texture m_backgroungs[NUM_OF_BACKGROUNDS];
	sf::Texture m_buttons_texures[NUM_OF_BACKGROUNDS];
	sf::SoundBuffer m_sound_buffer[NUM_OF_SOUNDES];
	sf::Font m_font;
	std::vector<std::string> m_levels_name;

	std::string m_FileNames[NUM_OF_TEXTURES] = {
	"mouse.png",
	"cat.png",
	"cheese.png",
	"door.png",
	"gift.png",
	"key.png",
	"wall.png",
	"freeze.png",
	"aid.png",
	"clock-30.png",
	"gift.png"
	};

	std::string m_DataTexturesNames[NUM_OF_DATA_TEXTURES] = {
	"clock-60.png",
	"heart.png",
	"star.png",
	"key.png"
	};

	std::string m_BackgroundsNames[NUM_OF_BACKGROUNDS] = {
	"backgroundmenu.png",
	"help.png",
	"backgroundtile.png",
	};

	std::string m_Button[NUM_OF_BUTTONS] = {
	"play button.png",
	"help button.png",
	"exit button.png",
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