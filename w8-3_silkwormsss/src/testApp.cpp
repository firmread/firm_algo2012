#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(0,0,0);
    ofEnableAlphaBlending();
    
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
    ofSetWindowShape(1200, 500);

    worm.setup();
    worming.setup();
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
    
    //start delay to see bouncy jump start
    if (ofGetElapsedTimeMillis()>250) {
        worm.resetForce();
        worm.gravity();
        worm.update();
        worming.resetForce();
        worming.update();
        worming.moveToPoint(
                            
                            ofGetWidth()/2
                            + ofGetWidth()/3*sin(ofGetElapsedTimef()*3)
                            + 150*cos(ofGetElapsedTimef()*3)
                            + 150*sin(ofGetElapsedTimef()*3),
                            
                            ofGetHeight()/3
                            + 150*cos(ofGetElapsedTimef()*3)
                            
                            );
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPushMatrix();
    ofTranslate(0, 0, -200);
    
        ofPushMatrix();
        ofTranslate(0, 0, 100);
            //draw frame
            ofFill();    
            int frameSize = 100;
            int lineOffset = 10;
            int offset = 50;
            ofSetLineWidth(20);
            for (int i = 0; i<frameSize; i++) {
                ofSetColor(ofMap(i, frameSize, 0, 0, 200), 150);
                ofLine(-offset, 0, -i*lineOffset, ofGetWidth()+offset, 0, -i*lineOffset);
            }
        
            for (int i = 0; i<frameSize; i++) {
                ofSetColor(ofMap(i, frameSize, 0, 0, 200), 150);
                ofLine(-offset, ofGetHeight(), -i*lineOffset, ofGetWidth()+offset, ofGetHeight(), -i*lineOffset);
            }
            ofSetLineWidth(1);
        ofPopMatrix();

        worm.draw();
        worming.draw();
 
    ofPopMatrix();

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	switch (key){
			
		case ' ':

            worm.resetPosition();
            worming.resetPosition();
			break;
	}
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    worm.moveToPoint(x, y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    worm.fixHead();
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	worm.releaseHead();
}

