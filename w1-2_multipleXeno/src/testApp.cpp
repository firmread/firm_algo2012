#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
	ofSetVerticalSync(true);
    ofBackground(30);
    ofEnableAlphaBlending();
    
	pct = 0;
    
    ofSetCircleResolution(10);
    
    for (int i = 0; i < 800; i++){
        s.setup();
        spots.push_back(s);
    }
    
    algologo.loadImage("algologo.png");

}

//--------------------------------------------------------------
void testApp::update(){
    
    //CircleResolution ease
	pct += 0.005f;
	if (pct > 1) pct = 0;
    ofSetCircleResolution(3+(pct)*5);
    
    
    for (int i = 0; i < 100; i++){
//        myCircles[i].xenoToPoint(mouseX+ofMap(i, 0, 9, -100, 100), mouseY+ofRandom(-100,100));
        if (i==0) {
            myCircles[0].xenoToPoint(mouseX, mouseY);
        }
        if (i!=0) {
            myCircles[i].xenoToPoint(myCircles[i-1].pos.x, myCircles[i-1].pos.y);
        }
    }
    
    for (int i = 0; i < 800; i++){
        spots[i].update(ofPoint(mouseX, mouseY));
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){

    ofSetColor(255);
    algologo.draw(ofGetWidth()- 125,ofGetHeight()-120, 100*algologo.width/algologo.height, 100);
	
    for (int i = 0; i < 800; i++){
        spots[i].draw();
    }
    
    
    for (int i = 0; i < 100; i++){
        //if (i == 3) ofSetColor(255,0,0);
        ofSetColor(ofMap(i, 0, 99, 255, 50),ofMap(i, 0, 99, 200, 100));
        myCircles[i].draw();
    }
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
//    if (key == 'f'||key == 'F') {
//        ofToggleFullscreen();
//    }
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}