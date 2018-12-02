#include "ofApp.h"
#include <iostream>

time_t rawtime;

extern SCREEN_STATUS status;

inline SCREEN_STATUS operator++(SCREEN_STATUS eDOW, int);

void ofApp::osc208()
{
	bang = 0;
	while ( receiver.hasWaitingMessages() )
	{

		ofxOscMessage m;
		receiver.getNextMessage(&m);

		for ( int i = 0; i < m.getNumArgs(); i++ )
		{
			if ( m.getArgType(i) == OFXOSC_TYPE_FLOAT )
			{
				bang = m.getArgAsFloat(0);
			}
		}
	}

	if ( mbangsw == 1 )
	{
		bang = 1;
	}

	if ( abb == 1 )
	{
		abbco += 1;
		if ( abbco > 200 )
		{
			abb = 0; abbco = 0;
		}
	}

}

//--------------------------------------------------------------
void ofApp::setup(){
    videoPlayer = new ofVideoPlayer();
	
	background.load("mailbox/Background.png");
	background.rotate90(3);
    
	score.setup();
	flying.setup();
	girl.setup();
    mailBox.load("mailbox/MAILBOX.png");
    mailBox.rotate90(3);
	table.load("mailbox/TABLE.png");
	table.rotate90(3);
    message.load("mailbox/MESSAGE.png");
    message.rotate90(3);
    letterBackground.load("mailbox/letterbackground.png");
    letterBackground.rotate90(3);
    
    cout<<"setup";

    //fingerMovie2.load("movies/fingers.mov");
    mailInfo.setup();
    
    background.load("mailbox/Background.png");
    background.rotate90(3);
    
    handWritingVideo.setup();
    mailImage.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	osc208();

	cout << status << endl;
	if ( bang != 0 && abb == 0 && completeCounter == -1 )
	{
		abb = 1;
		if ( word_writing )return;
		if ( c_index <= c_endIndex )return;
		test = true;

		// Log the check-time in the ~/bin/data/log.txt
		time(&rawtime);
		myTextFile.open("log.txt", ofFile::Append);
		myTextFile << ctime(&rawtime);
		myTextFile.close();

		switch ( status )
		{
		case NONTAG: status = FIRSTTAG;break;
		case FIRSTTAG: status = LASTTAG_UP; break;
		default: break;
		}
		score.onTagged();
	}

	flying.update();
	girl.update();
    videoPlayer->update();
    mailInfo.update();
    
    switch (status) {
        case FIRSTTAG:
            handWritingVideo.update();
            break;
        case LASTTAG_UP:
            mailImage.update();
            break;
                
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cout<<"height" <<endl;
    cout<<ofGetWidth()<<endl;
    //videoPlayer->draw(0, 0, 400, 300);
    //videoPlayer->play();
    background.draw(0, 0, 1920, 1080);
    ofPushMatrix();
    ofTranslate(0, -1080);
    //seventeen.draw();

    
	//flying.draw();
    mailBox.draw(0, 1080, 1920, 1080);
    girl.draw();

    table.draw(0, 1080, 1920, 1080);
    score.draw();

    switch (status){
        case NONTAG:{
            message.draw(0,1080,1920,1080);
            break;
        }
        case FIRSTTAG:{
            //손글씨 영상 재생
            letterBackground.draw(0,1080, 1920,1080);
            handWritingVideo.draw();
            break;
        }
        case LASTTAG_UP:{
            letterBackground.draw(0,1080, 1920,1080);
            mailImage.draw();
            break;
        }
        
    }
    // 두번째 화면
    //mailInfo.draw();
    
	ofPopMatrix();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	mbangsw = 1;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
	mbangsw = 0;
}


//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

double getCurrentMonitorPosition(int input, int ofResolution){
    double tmp = input / 1080;
    return ofResolution * tmp;
    
}

/*
 
 #include "ofApp.h"
 #include <iostream>
 
 time_t rawtime;
 
 extern SCREEN_STATUS status;
 
 inline SCREEN_STATUS operator++(SCREEN_STATUS eDOW, int);
 
 void ofApp::osc208()
 {
 bang = 0;
 while ( receiver.hasWaitingMessages() )
 {
 
 ofxOscMessage m;
 receiver.getNextMessage(&m);
 
 for ( int i = 0; i < m.getNumArgs(); i++ )
 {
 if ( m.getArgType(i) == OFXOSC_TYPE_FLOAT )
 {
 bang = m.getArgAsFloat(0);
 }
 }
 }
 
 if ( mbangsw == 1 )
 {
 bang = 1;
 }
 
 if ( abb == 1 )
 {
 abbco += 1;
 if ( abbco > 200 )
 {
 abb = 0; abbco = 0;
 }
 }
 
 }
 
 //--------------------------------------------------------------
 void ofApp::setup(){
 seventeen.setup();
 
 background.load("meal/Background.png");
 background.rotate90(3);
 score.setup();
 flying.setup();
 lady.setup();
 table.load("meal/Table.png");
 table.rotate90(3);
 pot.setup();
 }
 
 //--------------------------------------------------------------
 void ofApp::update(){
 osc208();
 
 cout << status << endl;
 if ( bang != 0 && abb == 0 && completeCounter == -1 )
 {
 abb = 1;
 if ( word_writing )return;
 if ( c_index <= c_endIndex )return;
 test = true;
 
 // Log the check-time in the ~/bin/data/log.txt
 time(&rawtime);
 myTextFile.open("log.txt", ofFile::Append);
 myTextFile << ctime(&rawtime);
 myTextFile.close();
 
 switch ( status )
 {
 case NONTAG: status = FIRSTTAG;break;
 case FIRSTTAG: status = LASTTAG_UP; break;
 default: break;
 }
 
 score.onTagged();
 }
 
 seventeen.update();
 flying.update();
 lady.update();
 pot.update();
 }
 
 //--------------------------------------------------------------
 void ofApp::draw(){
 //ofPushMatrix();
 
 //ofTranslate(0, -1080);
 seventeen.draw();
 background.draw(0, 1080, 1920, 1080);
 score.draw();
 flying.draw();
 lady.draw();
 if ( status == LASTTAG_DOWN )
 {
 pot.draw();
 table.draw(0, 1080, 1920, 1080);
 }
 else
 {
 table.draw(0, 1080, 1920, 1080);
 pot.draw();
 }
 //ofPopMatrix();
 
 }
 
 //--------------------------------------------------------------
 void ofApp::keyPressed(int key){
 
 }
 
 //--------------------------------------------------------------
 void ofApp::keyReleased(int key){
 
 }
 
 //--------------------------------------------------------------
 void ofApp::mouseMoved(int x, int y ){
 
 }
 
 //--------------------------------------------------------------
 void ofApp::mouseDragged(int x, int y, int button){
 
 }
 
 //--------------------------------------------------------------
 void ofApp::mousePressed(int x, int y, int button)
 {
 mbangsw = 1;
 }
 
 //--------------------------------------------------------------
 void ofApp::mouseReleased(int x, int y, int button)
 {
 mbangsw = 0;
 }
 
 
 //--------------------------------------------------------------
 void ofApp::mouseEntered(int x, int y){
 
 }
 
 //--------------------------------------------------------------
 void ofApp::mouseExited(int x, int y){
 
 }
 
 //--------------------------------------------------------------
 void ofApp::windowResized(int w, int h){
 
 }
 
 //--------------------------------------------------------------
 void ofApp::gotMessage(ofMessage msg){
 
 }
 
 //--------------------------------------------------------------
 void ofApp::dragEvent(ofDragInfo dragInfo){
 
 }
 
 */
