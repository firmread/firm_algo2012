#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofEnableSmoothing();
    ofEnableAlphaBlending();
	ofSetVerticalSync(true);
    ofSetFrameRate(60);
	
	ofBackground(40);
	TPR.setup();
    
    for (int i = 0; i < TPRs.size(); i++) {
        TPRs[i].setup();
    }
	playbackStartTime = 0;
	
}


//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	
	// -------------------------- draw the line
	TPR.draw();
	
	// -------------------------- draw the point at the current time
	if (TPR.bHaveADrawing()){			// if we have a drawing to work with
		
		// figure out what time we are at, and make sure we playback cyclically (!)
		// use the duration here and make sure our timeToCheck is in the range of 0 - duration
		float timeToCheck = ofGetElapsedTimef() - playbackStartTime;
		while (timeToCheck > TPR.getDuration() && TPR.getDuration() > 0){
			timeToCheck -= TPR.getDuration();
		}
		
		// get the position and velocity at timeToCheck
		ofPoint pos = TPR.getPositionForTime(timeToCheck);
		ofPoint vel = TPR.getVelocityForTime(timeToCheck);
		
		// since velocity is a line, we want to know how long it is. 
		float lengthOfVel = ofDist(0,0,vel.x, vel.y);
		
		ofFill();
		ofSetColor(255,0,0);
		ofCircle(pos.x, pos.y, 2 + lengthOfVel/5.0);
		
	}
    
    
    // draw lines in the past
    for (int i = 0; i < TPRs.size(); i++) {
        TPRs[i].draw();
  
    
        if (TPRs[i].bHaveADrawing()){	
            float timeToCheck = ofGetElapsedTimef() - playbackStartTimeEach[i];
            while (timeToCheck > TPRs[i].getDuration() && TPRs[i].getDuration() > 0){
                timeToCheck -= TPRs[i].getDuration();
            }
            
            ofPoint pos = TPRs[i].getPositionForTime(timeToCheck);
            ofPoint vel = TPRs[i].getVelocityForTime(timeToCheck);
            
            float lengthOfVel = ofDist(0,0,vel.x, vel.y);
            
            ofFill();
            ofSetColor(255,0,0);
            ofCircle(pos.x, pos.y, 2 + lengthOfVel/5.0);
            
            
            //set each one to different parameter
            
            if (i == 0) {
                ofFill();
                ofSetColor(255,0,0);
                ofCircle(pos.x, pos.y, 2 + lengthOfVel/5.0);
            }
            
            if (i == 1) {
                ofFill();
                ofSetColor(0,255,0);
                ofCircle(pos.x, pos.y, 2 + lengthOfVel/5.0);
            }
            if (i == 2) {
                ofFill();
                ofSetColor(0,0,255);
                ofCircle(pos.x, pos.y, 2 + lengthOfVel/5.0);
            }
            
            if (i == 3) {
                ofFill();
                ofSetColor(255,0,255);
                ofCircle(pos.x, pos.y, 2 + lengthOfVel/5.0);
            }
            if (i == 4) {
                ofFill();
                ofSetColor(255,255,0);
                ofCircle(pos.x, pos.y, 2 + lengthOfVel/5.0);
            }
            
            
            
            
            
            
            
        }
    }
    
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	TPR.addPoint(x,y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	TPR.startDrawing(x,y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	TPR.endDrawing();
    TPRs.push_back(TPR);
    playbackStartTimeEach.push_back(playbackStartTime);
	playbackStartTime = ofGetElapsedTimef();
    TPR.clear();
    
    if (TPRs.size()> 5) {
        TPRs.erase(TPRs.begin());
        playbackStartTimeEach.erase(playbackStartTimeEach.begin());
    }
    
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}



