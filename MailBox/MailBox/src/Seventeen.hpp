#pragma once
#include "ofMain.h"

class Seventeen
{
private:
	ofImage heart[17];
	int count;
	int isChanged;
	const int CHANGETIME = 100;

public:
	void setup();
	void update();
	void draw();

};