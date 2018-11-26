#pragma once
#include "ofMain.h"
#include <cmath>



enum SCREEN_STATUS
{
	NONTAG, FIRSTTAG, LASTTAG_UP, LASTTAG_DOWN, LASTTAG_NEW
};
inline SCREEN_STATUS operator++(SCREEN_STATUS eDOW, int);
const float INTERVAL = 5;




class Lady
{
public:
	void setup();
	void update();
	void draw();
	
private:
	ofImage lady[3];
	int index;
	float x, y;
	SCREEN_STATUS prevStatus = NONTAG;

};

class Pot
{
public:
	void setup();
	void update();
	void draw();

private:
	ofImage pot[4];
	const int POTCHANGE = 30;
	int index;
	float x, y;
	SCREEN_STATUS prevStatus = NONTAG;
	int potcount = POTCHANGE;
};

class Flying
{
public:
	void setup();
	void update();
	void draw();

private:
	ofImage flying;
	float x;
	int count;
};

class Score
{
public:
	void setup();
	void onTagged();
	void draw();

private:
	ofImage score[10];
	int score_count = 0;
	const float width = 130;
	const float positionX = 360, positionY = 400;
};