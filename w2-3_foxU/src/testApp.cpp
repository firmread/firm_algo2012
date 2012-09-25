#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    
    ofEnableAlphaBlending();
    ofBackground(255);
    
    ofSetFrameRate(60);
    aFox.setup(mouseX,mouseY, 0.05f);
    
    
//    for (int i=0; i<2; i++) {
//        foxes[i].setup(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),0.01f);
//    }

}

//--------------------------------------------------------------
void testApp::update(){
    aFox.xenoToPoint(mouseX, mouseY);
    ura.update(mouseX, mouseY);
//    for (int i=0; i<foxes.size(); i++) {
//        foxes[i].xenoToPoint(mouseX, mouseY);
//    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ura.draw(mouseX,mouseY, 15);
    ofSetColor(255,100);
    aFox.draw(mouseX, mouseY);
//    for (int i=0; i<foxes.size(); i++) {
//        foxes[i].draw(mouseX, mouseY);
//    }
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
void testApp::mouseMoved(int x, int y){

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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}