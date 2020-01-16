#pragma once
#include "SDL_mixer.h"

class Music
{
public:
	Mix_Music* bgm;
	Mix_Chunk* hurt;
	Mix_Chunk* mouseOver; Mix_Chunk* mouseClick;
	bool IsMusicOn = false;
	Music() {}
	~Music() {}

	void BaseMusic()
	{
		//SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); // Initializes Mixer to use Music
		bgm = Mix_LoadMUS("Assets/Music/"); // Loads Music File
		Mix_PlayMusic(bgm, -1); // Loops the Music so it constantly plays
	}

	

	void MuteMusic()
	{
		if (IsMusicOn == false)
		{
			Mix_VolumeMusic(0);
			IsMusicOn = true;
		}
		else if (IsMusicOn)
		{
			Mix_VolumeMusic(10);
			IsMusicOn = false;
		}
	}

	void ExitMusic()
	{
		bgm = nullptr;
		Mix_Quit(); // Stops Music as game is closed
	}
};