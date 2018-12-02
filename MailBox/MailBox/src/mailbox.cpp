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
    count = CHANGETIME;
    index = 0;
    x = 0;
    y = 0;
}
void Girl::update()
{
    bool needInitial = (prevStatus != status);
    prevStatus = status;
    count--;
    if ( !count )
    {
        cout<<"update nontag !count"<<endl;
        
        index++;
        count = CHANGETIME;
        if ( index >= 3 )
        {
            index = 0;
        }
    }
    x = 0; y = 1080;
    /*
    switch ( status )
    {
        case NONTAG: {
            cout<<"update nontag"<<endl;
            count--;
            if ( !count )
            {
                cout<<"update nontag !count"<<endl;

                index++;
                count = CHANGETIME;
                if ( index >= 3 )
                {
                    index = 0;
                }
            }
            x = 0; y = 1080;
            break;
        }
        case FIRSTTAG: {
            x = 0;
            y = 1080;
            break;
        };
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
    }*/
}
void Girl::draw()
{
    // TODO
    switch (status) {
        case NONTAG:
            
            cout<<"nontag"<<endl;
            cout<<"index"<<endl;
            cout<<index<<endl;
            girlA[index].draw(0,1080, 1920, 1080);
            break;
        case FIRSTTAG:
            girlB[index].draw(0,1080, 1920, 1080);
            break;
            
        default:
            break;
    }
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
        score[i].load("mailbox/" + std::to_string(i) + ".png");
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
    
    score[one].draw(positionX + 1750, 335+positionY, width, width);
    score[ten].draw(positionX + 1750, 335+positionY+width, width, width);
    score[hundred].draw(positionX + 1750, 335+positionY+width*2 , width, width);
}

void HandWritingVideo::setup(){
    
    writingVideo = new ofVideoPlayer;
    writingVideo->load("mailbox/writing/output.mov");
    writingVideo->setLoopState(OF_LOOP_NONE);
    
}

void HandWritingVideo::update(){
    writingVideo->update();
}

void HandWritingVideo::draw(){
    //writingVideo->draw(0, 1080);
    ofRotate(270);
    writingVideo->draw(-945, 1010, 880, 635);
    
    //writingVideo->draw(0, 1080);
}

void Mail::setup()
{
    mail.load("mailbox/MAIL.png");
    mail.rotate90(3);
    x = 0;
    y = 0;
}

void Mail::update()
{
    mail.update();
    if ( isTagged )
    {
        move();
    }
    
}
void Mail::draw()
{
    mail.draw(x, y + 1080, 1920, 1080);
}
void Mail::move()
{
    if( y < 280)
    {
        y += INTERVAL;
    }
    if ( y >= 280 && x < 900)
    {
        x += INTERVAL;
        
    }
    
    
    
}
void Mail::onTagged()
{
    isTagged = true;
}
