//
//  mailInfo.hpp
//  allAddonsExample
//
//  Created by 박재성 on 03/12/2018.
//

#pragma once
#include "ofMain.h"
class MailInfo
{
public:
    void setup();
    void update();
    void draw();
    
private:
    ofImage Background[4];
    int count;
    int isChanged;
    const int CHANGETIME = 100;
    
    ofVideoPlayer* mailVideo;
};
