#include "Images.h"

Logo::Logo()
{

	m_pLogoSurface = IMG_Load("Assets/Logo.png");

	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 450;
	m_rSrc.h = 382;

	m_rDst.x = 574 / 2;
	m_rDst.y = 386 / 2;
	m_rDst.w = 450;
	m_rDst.h = 382;

}

Paused::Paused()
{
	m_pPauseSurface = IMG_Load("Assets/Pause.png");

	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 446;
	m_rSrc.h = 165;

	m_rDst.x = 781;
	m_rDst.y = 25;
	m_rDst.w = 446 / 2;
	m_rDst.h = 165 / 2;
}

Win::Win()
{
	m_pWinSurface = IMG_Load("Assets/win.png");
	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 460;
	m_rSrc.h = 373;

	m_rDst.x = 564 / 2;
	m_rDst.y = 391 / 2;
	m_rDst.w = 460;
	m_rDst.h = 373;
}

Lose::Lose() {
	m_pLoseSurface = IMG_Load("Assets/lose.png");
	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 460;
	m_rSrc.h = 373;

	m_rDst.x = 564 / 2;
	m_rDst.y = 391 / 2;
	m_rDst.w = 460;
	m_rDst.h = 373;
}

GroupLogo::GroupLogo()
{
	m_pGroupLogoSurface = IMG_Load("Assets/Sample3.png");
	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 400;
	m_rSrc.h = 128;

	m_rDst.x = 624;
	m_rDst.y = 640;
	m_rDst.w = 400;
	m_rDst.h = 128;
}
