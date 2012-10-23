#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    ofEnableAlphaBlending();
	
    
    ofSoundStreamSetup(0, 2, this, 44100, BUFFER_SIZE, 4);
    left = new float [BUFFER_SIZE];
    right= new float [BUFFER_SIZE];
    FFTanalyzer.setup(44100, BUFFER_SIZE/2, 2);
    
    FFTanalyzer.peakHoldTime    = 30;
    FFTanalyzer.peakDecayRate   = 0.095f;
    FFTanalyzer.linearEQIntercept = 0.9f;
    FFTanalyzer.linearEQSlope   = 0.01f;

	
	for (int i = 0; i < 500; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}
	
	VF.setupField(200,200,ofGetWidth(), ofGetHeight());
	VF.randomizeField(2.0);
	
    
	smoothedVol     = 0.0;
	scaledVol		= 0.0;
    
    
	drawingStyle = 0;
	bFade = false;
    ofBackground(30);
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	//particles
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		
		// get the force from the vector field: 
		ofVec2f frc;
		frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
		particles[i].addForce(frc.x, frc.y);
        
        for (int j = 0; j < i; j++){
			particles[i].addRepulsionForce(particles[j], 10, 1);
//			particles[i].addCounterClockwiseForce(particles[j], 5, 0.9);
		}
        
		particles[i].addDampingForce();
        particles[i].bounceOffWalls();
		particles[i].update();
	}
	
    
	//lets scale the vol up to a 0-1 range
	scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
	//vector fields
	if (bFade == true) VF.fadeField(0.99f);

    if (ofGetElapsedTimeMillis()%200 < 30) {
        VF.randomizeField(4.0);
    }
    
    VF.addClockwiseCircle(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth(), 0.5f);
    VF.addInwardCircle(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth(),scaledVol*1.3
                    );
//    VF.addInwardCircle(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth(), sin(ofGetElapsedTimeMillis()*0.001)+0.5);
    cout << scaledVol << endl;
    
    
    
    //fft
    float avg_power = 0.0f;
    myfft.powerSpectrum(0, (int) BUFFER_SIZE/2, left, BUFFER_SIZE, &magnitude[0], &phase[0], &power[0], &avg_power);
    
    for(int i = 0; i<BUFFER_SIZE/2; i++){
        freq[i] = magnitude[i];
    }
    FFTanalyzer.calculate(freq);

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();
//	ofSetColor(0,130,130, 50);
    ofSetColor(150,20);
    
	VF.draw();
	
	ofSetColor(0,0,0);
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
//	ofSetColor(0,130,130, 200);
//	ofRect(30,30,300,75);
//	ofSetColor(255,255,255);
//	ofDrawBitmapString("space to clear\nchange drawing mode 'a'\ntoggle fade 'f'", 50, 50);
//	
//	
//	ofSetColor(255,255,130);
//	switch (drawingStyle){
//		case 0: ofDrawBitmapString("drawing mode: inward", 50, 90);
//			break;
//		case 1: ofDrawBitmapString("drawing mode: outward", 50, 90);
//			break;
//		case 2: ofDrawBitmapString("drawing mode: clockwise", 50, 90);
//			break;
//		case 3: ofDrawBitmapString("drawing mode: counter-clockwise", 50, 90); 
//			break;
//	}
    
    ofPushMatrix();
    ofTranslate(0, ofGetHeight());
    
    for (int i = 0 ; i< FFTanalyzer.nAverages; i++) {
        
//        
//        ofSetColor(255, FFTanalyzer.averages[i]*20);
//        ofCircle(i*70, -FFTanalyzer.averages[i]*20, FFTanalyzer.averages[i]);
        
    }
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	if (key == ' '){
		VF.clear();
	} else if (key == 'a'){
		drawingStyle ++;
		drawingStyle %= 4;
	} else if (key == 'f'){
		bFade = !bFade;
	} else if (key == 'r'){
        VF.randomizeField(4.0);
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
//	if (button == 0) {
//		switch (drawingStyle){
//			case 0: VF.addInwardCircle((float)x, (float)y, 200, 0.3f);
//				break;
//			case 1: VF.addOutwardCircle((float)x, (float)y, 100, 0.3f);
//				break;
//			case 2: VF.addClockwiseCircle((float)x, (float)y, ofGetWidth(), 0.9f);
//				break;
//			case 3: VF.addCounterClockwiseCircle((float)x, (float)y, ofGetWidth(), 0.9f);
//				break;
//		}		
//	} else {
//		
		particles.erase(particles.begin());
		particle myParticle;
		myParticle.setInitialCondition(x,y,0,0);
		particles.push_back(myParticle);
//
//		
//	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}

//--------------------------------------------------------------
void testApp::audioIn (float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
	int numCounted = 0;
    
    for (int i = 0; i < bufferSize; i++){
        left [i]    =   input [i*2  ];
        right[i]    =   input [i*2+1];
        
		curVol += left[i] * left[i];
		curVol += right[i] * right[i];
		numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
	curVol /= (float)numCounted;
	
	// this is how we get the root of rms :)
	curVol = sqrt( curVol );
	
	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
	
	bufferCounter++;
}
