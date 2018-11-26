#include "Seventeen.hpp"

void Seventeen::setup()
{
	for ( int i = 0; i < 17; i++ )
	{
		heart[i].load("svthearts/" + std::to_string(i + 1) + ".jpg");
		heart[i].rotate90(3);
	}
	isChanged = 0;
	count = CHANGETIME;
}

void Seventeen::update()
{
	count--;
	if ( !count )
	{
		isChanged++;
		count = CHANGETIME;
		if ( isChanged >= 17 )
		{
			isChanged = 0;
		}
	}
}

void Seventeen::draw()
{
	heart[isChanged].draw(0, 0, 1920, 1080);
}