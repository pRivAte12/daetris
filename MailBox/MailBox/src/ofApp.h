#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "Seventeen.hpp"
#include "mailbox.hpp"
#include "mailInfo.hpp"
class ofApp : public ofBaseApp{

	public:
        ofVideoPlayer* videoPlayer;

		void setup();
		void update();
		void draw();


		void osc208();

		ofxOscReceiver receiver;

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		ofFile myTextFile;
		int completeCounter = -1;

		bool word_writing = false;
		int c_endIndex = -1;
		int c_index = 0;
		bool test = false;

		float bang;
		int mbangsw;
		int abb;
		int abbco;
    
        MailInfo mailInfo;
    
		Seventeen seventeen;
		Girl girl;
		Flying flying;
		Score score;

		ofImage background;
		ofImage table;
        ofImage mailBox;
        ofImage message;
    

};
