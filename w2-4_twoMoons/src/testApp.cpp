/*
 'Two Moons'
 Performed by Toe
 Algorithmic animation by Firm Read Tothong
 
 *** need to play music out on loudspeaker and microphone in computer
 to work properlly***
 */

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSoundStreamSetup(0, 2, this, 44100, BUFFER_SIZE, 4);
    left = new float [BUFFER_SIZE];
    right= new float [BUFFER_SIZE];
    FFTanalyzer.setup(44100, BUFFER_SIZE/2, 2);
    
    FFTanalyzer.peakHoldTime    = 30;
    FFTanalyzer.peakDecayRate   = 0.095f;
    FFTanalyzer.linearEQIntercept = 0.9f;
    FFTanalyzer.linearEQSlope   = 0.01f;
    
    ofBackground(40);
    ofEnableAlphaBlending();
    twomoons.loadSound("twomoons.mp3");
    twomoons.play();
    twomoons.setLoop(true);
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void testApp::update(){
    float avg_power = 0.0f;
    myfft.powerSpectrum(0, (int) BUFFER_SIZE/2, left, BUFFER_SIZE, &magnitude[0], &phase[0], &power[0], &avg_power);
    
    for(int i = 0; i<BUFFER_SIZE/2; i++){
        freq[i] = magnitude[i];
    }
    FFTanalyzer.calculate(freq);
    
}

//--------------------------------------------------------------
void testApp::draw(){

    float sine = sin(ofGetElapsedTimef()/10.0f) ;

    
    for (int i = 0; i < BUFFER_SIZE/2; i++) {
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, 0);
        ofSetColor(255,150);
        ofRect(0, i*4, -freq[i]*10.0f, 2);
        ofPopMatrix();
        
        //first moon
        
        float xorig = ofGetWidth()/4;
        float yorig = ofGetHeight()/3 + sine*100;
        
        ofFill();
        for (int i = 0; i < 100; i++){
            float radius = 10 + i * 2;
            float angle = ofGetElapsedTimef() * (1 + i / 1.0);
            float x = xorig + radius * cos(angle);
            float y = yorig + radius * -sin(angle);
            ofSetColor(247, 219, 126,freq[i]*2);
            ofCircle(x, y, -freq[i]*1.0f);
        }
        
        //-------
        
        
        //second moon
        
        ofPushMatrix();
        ofTranslate(ofGetWidth()*3/4, ofGetHeight()/2-sine*100);
        ofNoFill();
        ofSetLineWidth(1);
        ofScale(freq[i]/8.0f,freq[i]/8.0f);
        ofBeginShape();
        ofSetColor(220,freq[i]*3.0f);
        for (int j = 0; j < 40; j++){
            float radius2 = 5 + j * 2;
            float angle2 = ofGetElapsedTimef() * (1 + j / 3.0);
            float x = radius2 * cos(angle2);
            float y = radius2 * sin(angle2);
            
            ofVertex(x, y);
        }
        ofEndShape();
        ofPopMatrix();
        
        //-------
        
    }
    
    ofFill();
    ofPushMatrix();
    ofTranslate(0, ofGetHeight());
    ofBeginShape();
    ofVertex(0, ofGetHeight());
    ofSetColor(40, 80, 20,150);
    
    for (int i = 0;i < FFTanalyzer.nAverages; i++){
//        ofPoint posIn = (i*70, -FFTanalyzer.averages[i]*15);
//        ofPoint posOut;
//        float catchspeed = 0.9f;
//        posOut.x = catchspeed * posIn.x + (1-catchspeed) * posOut.x;
//        posOut.y = catchspeed * posIn.y + (1-catchspeed) * posOut.y;
        
        
        ofCurveVertex(i*70, -FFTanalyzer.averages[i]*15);
        
        
    }
    ofVertex(ofGetWidth(), ofGetHeight());
    ofEndShape();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(0, ofGetHeight());
    
    for (int i = 0 ; i< FFTanalyzer.nAverages; i++) {
    
        
        ofSetColor(255, FFTanalyzer.averages[i]*20);
        ofCircle(i*70, -FFTanalyzer.averages[i]*20, FFTanalyzer.averages[i]);
   
    }
    ofPopMatrix();

}

//--------------------------------------------------------------
void testApp::audioIn (float * input, int bufferSize, int nChannels){
    for (int i = 0; i < bufferSize; i++){
        left [i]    =   input [i*2  ];
        right[i]    =   input [i*2+1];
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    if(key=='f'||key=='F'){
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

