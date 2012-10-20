#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    ofBackground(40);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
//    ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
//    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	
    for (int i=0; i<NUM_FIRE; i++) {
        firing[i].setup();
    }
	
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i=0; i<NUM_FIRE; i++) {
        firing[i].update();
        if (ofGetElapsedTimeMillis()%1000 > 100*i && ofGetElapsedTimeMillis()%1000 < 100*i+100) {
            firing[i].refire(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        }
    }

//    if (ofGetElapsedTimeMillis()%6000<100) {
//        firing[0].refire(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
//        
//    }
//    if (ofGetElapsedTimeMillis()%6000>3000 && ofGetElapsedTimeMillis()%6000<3100) {
//        firing[1].refire(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
//    }
//    cout << ofGetElapsedTimeMillis()%6000 << endl;

}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i=0; i<NUM_FIRE; i++) {
        firing[i].draw();
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    if (key == 'f' || key == 'F') {
        ofToggleFullscreen();
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
//    check +=1;
//    
//    if (check == 1) {
//        firing[0].refire(x, y);
//    }
//    else if(check == 2){
//        firing[1].refire(x, y);
//        check = 0;
//    }

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    check +=1;
    
    if (check == 1) {
        firing[0].refire(x, y);
    }
    else if(check == 2){
        firing[1].refire(x, y);
        check = 0;
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
