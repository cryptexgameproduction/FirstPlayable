#include "Sprite.h"

const SDL_Rect* Sprite::getSource()
{

	return &m_rSrc;

}

const SDL_Rect* Sprite::getDes()
{

	return &m_rDst;

}

