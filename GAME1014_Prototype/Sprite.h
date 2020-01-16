#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

class Sprite
{

public:
	int m_iRad;
	SDL_Rect m_rSrc;
	SDL_Rect m_rDst;

	const SDL_Rect*getSource();

	const SDL_Rect*getDes();


private:


};