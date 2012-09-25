#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(240);
	
	ofSetCircleResolution(100);
    ofEnableAlphaBlending();
    ofSetFrameRate(30);

}

//--------------------------------------------------------------
void testApp::update(){
	
	
	

}

//--------------------------------------------------------------
void testApp::draw(){
	
	float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;
	
    ofFill();
    ofBeginShape();
	for (int i = 0; i < 200; i++){
		float radius = 10 + i * 2;
		float angle = ofGetElapsedTimef() * (1 + i / 30.0);
		float x = xorig + radius * cos(angle);
		float y = yorig + radius * -sin(angle);
		//ofSetColor(41,171,226,50);
        ofSetColor(247, 219, 126,250);
        ofVertex(x, y);
	}
    ofEndShape();
		
    ofNoFill();
    ofSetLineWidth(1);
    ofBeginShape();
	for (int i = 0; i < 200; i++){
		float radius = 5 + i * 2;
		float angle = ofGetElapsedTimef() * (1 + i / 31.0);
		float x = xorig + radius * -cos(angle);
		float y = yorig + radius * sin(angle);
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofSetColor(20,100);
        ofVertex(x, y);
	}
    ofEndShape();
    
    
    
	

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

