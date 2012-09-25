/* 
 algo 2012 by Firm Read Tothong
 "Strugling Between Chaos and Order"
 
 In this interactive piece, which the user can move mouse in X axis to interact with
 at the middle of the frame is where the balance and order is. (sine/cos animation)
 while a the edge of both side is chaos (random function).
 This piece depend on the idea of xeno, 
 it try to smooth out randomness and it can work at full power at the middle of the canvas.
 
 in the context of window installation, it may take input from wind
 where it blow into random mode when the wind pass by.
 
*/

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(41);

	ofSetCircleResolution(100);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);

}

//--------------------------------------------------------------
void testApp::update(){
	
	
	

}

//--------------------------------------------------------------
void testApp::draw(){
	
	float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;
	
    ofSetColor(255,200);
    
    for (int i = 0; i < 200; i++){
		float radius = 10 + i * 2;
		float angle = ofGetElapsedTimef() * (1 + i / 30.0);
		float x = xorig + radius * cos(angle);
		float y = yorig + radius * -sin(angle);
        ofPushMatrix();
        
            //xeno+ramdom+rotate
        
            float catchUpSpeed = ofMap(mouseX, 0, ofGetWidth(), 0.001f, 2.0f,true);
            cout << catchUpSpeed << endl;
            int randomized = catchUpSpeed * ofRandom(1.0) + (1-catchUpSpeed) * randomized;
            ofRotate(randomized * sin(angle));
            ofCircle(x, y, 10 * sin(angle)+cos(-angle));
        ofPopMatrix();
	}

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key=='f' || key=='F'){
        ofToggleFullscreen();
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

