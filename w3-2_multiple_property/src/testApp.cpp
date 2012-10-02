#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofEnableSmoothing();
    ofEnableAlphaBlending();
	ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetCircleResolution(100);
	
    ofColor c(94, 166, 250);
	cbg = c;
	TPR.setup();
    
    for (int i = 0; i < TPRs.size(); i++) {
        TPRs[i].setup();
    }
	playbackStartTime = 0;
    brownLoop.loadSound("brown.mp3");
    brownLoop.setVolume(0);
    brownLoop.setLoop(true);
    brownLoop.play();
	
    ofSetLineWidth(1.2);
}


//--------------------------------------------------------------
void testApp::update(){
    ofBackground(cbg);
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
        float angle = atan2(vel.y, vel.x);

		
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
            float angle = atan2(vel.y, vel.x);
            
            //set each one to different parameter
            
            if (i == 0) {
                
                float brownVolumn = ofMap(lengthOfVel, 0, 200, 0, 1);
                brownLoop.setVolume(brownVolumn);
                
                float pitch = ofMap(pos.y, 0, (float)ofGetHeight(), 2.0, 0.1);
                brownLoop.setSpeed(pitch);
                
                float pan = ofMap(pos.x, 0, (float)ofGetWidth(), -1,1);
                brownLoop.setPan(pan);
                
                
                ofColor c(200);
                elasEllipse current;
                current.draw(pos.x, pos.y, c, lengthOfVel, angle);
            }
//            94 166 250
            if (i == 1) {
                
                cbg.r = ofMap(lengthOfVel, 0, 200, 70 , 100);
                cbg.g = ofMap(pos.x, 0, (float)ofGetWidth(), 100, 170);
                cbg.b = ofMap(pos.y, 0, (float)ofGetHeight(), 200, 250);
                
                ofColor c(47, 82, 120);
                elasEllipse current;
                current.draw(pos.x, pos.y, c, lengthOfVel, angle);
            }
            
            
//            if (i == 2) {
//                
//                
//                cbg.g = ofMap(lengthOfVel, 0, 200, 130, 160);
//                
//                ofColor c(97,166,250);
//                elasEllipse current;
//                current.draw(pos.x, pos.y, c, lengthOfVel, angle);
//            }
//            
//            if (i == 3) {
//                
//                
//                cbg.b = ofMap(lengthOfVel, 0, 200, 240, 255);
//                
//                ofColor c(240,224,70);
//                elasEllipse current;
//                current.draw(pos.x, pos.y, c, lengthOfVel, angle);
//            }
//            if (i == 4) {
//                ofColor c(205,115,40);
//                elasEllipse current;
//                current.draw(pos.x, pos.y, c, lengthOfVel, angle);
//            }
            
            
            
            
            
            
            
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
    
    if (TPRs.size()> 2) {
        TPRs.erase(TPRs.begin());
        playbackStartTimeEach.erase(playbackStartTimeEach.begin());
    }
    
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}



