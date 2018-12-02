//
//  mailbox.cpp
//  allAddonsExample
//
//  Created by 박재성 on 02/12/2018.
//

#include "mailbox.hpp"
#define PI 3.1415926535

SCREEN_STATUS status = NONTAG;

extern inline SCREEN_STATUS operator++(SCREEN_STATUS eDOW, int)
{
    const int i = static_cast<int>(eDOW);
    return static_cast<SCREEN_STATUS>((i + 1) % 5);
}
void Girl::setup()
{
    // Initializing girlA
    for ( int i = 0; i < 3; i++ )
    {
        girlA[i].load("mailbox/GIRL" + std::to_string(i + 1) + "A.png");
        girlA[i].rotate90(3);
    }
    
    // Initializing girlB
    for ( int i = 0; i < 3; i++ )
    {
        girlB[i].load("mailbox/GIRL" + std::to_string(i + 1) + "B.png");
        girlB[i].rotate90(3);
    }
    
    // Initializing girlC
    
    for ( int i = 0; i < 3; i++ )
    {
        girlC[i].load("mailbox/GIRL" + std::to_string(i + 1) + "C.png");
        girlC[i].rotate90(3);
    }
    index = 0;
    x = 0;
    y = 0;
}
void Girl::update()
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
void Girl::draw()
{
    // TODO
}
//--------------------------------------------------------------------

void Flying::setup()
{
    flying.load("mailbox/MESSAGE.png");
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

