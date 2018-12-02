//
//  mailbox.hpp
//  allAddonsExample
//
//  Created by 박재성 on 02/12/2018.
//
#pragma once
#include "ofMain.h"
#include <cmath>



enum SCREEN_STATUS
{
    NONTAG, FIRSTTAG, LASTTAG_UP, LASTTAG_DOWN, LASTTAG_NEW
};
inline SCREEN_STATUS operator++(SCREEN_STATUS eDOW, int);
const float INTERVAL = 5;




class Girl
{
public:
    void setup();
    void update();
    void draw();
    
private:
    ofImage girlA[2];
    ofImage girlB[2];
    int index; // 0 -> A 1 -> B
    float x, y;
    SCREEN_STATUS prevStatus = NONTAG;
    
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
    const float width = 103;
    const float positionX = 0, positionY = 1080;
};
