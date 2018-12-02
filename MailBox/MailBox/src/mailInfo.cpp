//
//  mailInfo.cpp
//  allAddonsExample
//
//  Created by 박재성 on 03/12/2018.
//

#include "mailInfo.hpp"
void MailInfo::setup()
{
    for ( int i = 0; i < 4; i++ )
    {
        Background[i].load("mailInfo/Background" + std::to_string(i + 1) + ".png");
        Background[i].rotate90(3);
    }
    isChanged = 0;
    count = CHANGETIME;
    
    mailVideo = new ofVideoPlayer;
    mailVideo->load("mailInfo/mail_video.mp4");
    mailVideo->setLoopState(OF_LOOP_NONE);
    
}

void MailInfo::update()
{
    count--;
    if ( !count )
    {
        isChanged++;
        count = CHANGETIME;
        if ( isChanged >= 4 )
        {
            isChanged = 0;
        }
    }
    mailVideo->update();
    if ( mailVideo->getIsMovieDone() )
    {
        delete mailVideo;
        mailVideo = new ofVideoPlayer;
        mailVideo->load("mailInfo/mail_video.mp4");
        mailVideo->setLoopState(OF_LOOP_NONE);
    }
}

void MailInfo::draw()
{
    Background[isChanged].draw(0, 0, 1920, 1080);
    ofRotate(270);
    mailVideo->draw(-945, 1010, 880, 635);
    mailVideo->play();
}
