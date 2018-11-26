#include "meal.hpp"
#define PI 3.1415926535

SCREEN_STATUS status = NONTAG;

extern inline SCREEN_STATUS operator++(SCREEN_STATUS eDOW, int)
{
	const int i = static_cast<int>(eDOW);
	return static_cast<SCREEN_STATUS>((i + 1) % 5);
}
void Lady::setup()
{
	for ( int i = 0; i < 3; i++ )
	{
		lady[i].load("meal/Lady" + std::to_string(i + 1) + ".png");
		lady[i].rotate90(3);
	}
	index = 0;
	x = 0;
	y = 0;
}
void Lady::update()
{
	bool needInitial = (prevStatus != status);
	prevStatus = status;
	switch ( status )
	{
	case NONTAG: index = 0; x = 0; y = 1080; break;
	case FIRSTTAG: index = 1; x = 0; y = 1080; break;
	case LASTTAG_UP: index = 2; x = 0; y = 1080; break;
	case LASTTAG_DOWN: index = 2; 
		if ( needInitial )
		{
			x = 0;
		}
		x += INTERVAL; y = 1080;
		break;
	case LASTTAG_NEW: index = 0;
		if ( needInitial )
		{
			x = 0;
			y = 1080 * 2;
		}
		y -= INTERVAL;
		break;
	}
}
void Lady::draw()
{
	lady[index].draw(x, y, 1920, 1080);
}

//----------------------------------------------------------------
void Pot::setup()
{
	for ( int i = 0; i < 4; i++ )
	{
		pot[i].load("meal/pot" + std::to_string(i + 1) + ".png");
		pot[i].rotate90(3);
	}
	index = 0; x = 0; y = 0;
}

void Pot::update()
{
	bool needInitial = (prevStatus != status);
	prevStatus = status;
	switch ( status )
	{
	case NONTAG: index = 0; x = 0; y = 1080; break;
	case FIRSTTAG:
		if ( needInitial )
		{
			index = 1;
		}
		potcount--;
		if ( !potcount )
		{
			if ( index == 1 )
			{
				index = 2;
			}
			else
			{
				index = 1;
			}
			potcount = POTCHANGE;
		}
		x = 0; y = 1080; break;
	case LASTTAG_UP: 
		index = 3;
		if ( needInitial )
		{
			x = 0;
		}
		x -= INTERVAL; 
		if ( x <= -400 )
		{
			status = LASTTAG_DOWN;
		}
		break;
	case LASTTAG_DOWN: 
		index = 3;
		x += INTERVAL; y = 1080;
		if ( x >= 1000 )
		{
			status = LASTTAG_NEW;
		}
		break;
	case LASTTAG_NEW: index = 0;
		if ( needInitial )
		{
			x = 0;
			y = 0;
		}
		y += INTERVAL;
		if ( y >= 1080 )
		{
			y = 1080;
			status = NONTAG;
		}
		break;
	}
}
void Pot::draw()
{
	pot[index].draw(x, y, 1920, 1080);
}
//--------------------------------------------------------------------

void Flying::setup()
{
	flying.load("meal/Flying.png");
	flying.rotate90(3);
	count = 0;
}

void Flying::update()
{
	x = sin((count++)*PI / 180) * 50;
}

void Flying::draw()
{
	flying.draw(x, 1080, 1920, 1080);
}

//-------------------------------------------------------------------------

void Score::setup()
{
	for ( int i = 0; i < 10; i++ )
	{
		score[i].load("meal/" + std::to_string(i) + ".png");
		score[i].rotate90(3);
	}
	
}

void Score::onTagged()
{
	score_count++;
}

void Score::draw()
{
	int hundred = score_count / 100;
	int ten = (score_count - hundred * 100) / 10;
	int one = (score_count - hundred * 100 - ten * 10);

	score[one].draw(positionX, 1080+positionY, width, width);
	score[ten].draw(positionX, 1080+positionY+width, width, width);
	score[hundred].draw(positionX, 1080+positionY+width*2 , width, width);
}