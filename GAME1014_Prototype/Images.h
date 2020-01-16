#pragma once

#include "Sprite.h"

class Logo : public Sprite
{

public:

	Logo();
	SDL_Surface* m_pLogoSurface;
private:
};

class Paused : public Sprite
{
public:
	Paused();
	SDL_Surface* m_pPauseSurface;
private:

};

class Win : public Sprite
{
public:
	Win();
	SDL_Surface* m_pWinSurface;
private:
};

class Lose : public Sprite
{
public:
	Lose();
	SDL_Surface* m_pLoseSurface;
private:
};

class GroupLogo : public Sprite
{
public:
	GroupLogo();
	SDL_Surface* m_pGroupLogoSurface;
private:
};