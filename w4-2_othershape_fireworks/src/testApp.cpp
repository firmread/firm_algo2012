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
	
    int basePoint = ofRandom(235);
    int eachr = ofRandom(5,20);
	for (int i = 0; i < 1000; i++){
		particle myParticle;
        float r = ofRandom(-eachr,eachr);
        float angle = ofRandom(180);
		float vx = r*cos(angle);
		float vy = r*sin(angle);
        
        ofColor c;
        c.setHsb(basePoint + ofRandom(30), 200, 255,100);
        myParticle.particleColor = c;
        
        myParticle.shape = ofRandom(3,8);
        myParticle.size = abs(r)*2;
		myParticle.setInitialCondition(300,300,vx, vy, angle);

		myParticle.damping = ofRandom(0.01, 0.05);
		particles.push_back(myParticle);
	}
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		particles[i].addForce(0,0.15);  // gravity
		particles[i].addDampingForce();
		particles[i].update();
	}

}

//--------------------------------------------------------------
void testApp::draw(){
    
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
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
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    int basePoint = ofRandom(235);
    int eachr = ofRandom(5,20);
	for (int i = 0; i < particles.size(); i++){
        float r = ofRandom(-eachr,eachr);
        float angle = ofRandom(180);
		float vx = r*cos(angle);
		float vy = r*sin(angle);
        
        ofColor c;
        c.setHsb(basePoint + ofRandom(30), 200, 255,100);
        particles[i].particleColor = c;
        
        particles[i].shape = ofRandom(3,8);
        particles[i].size = abs(r)*2.2;
		particles[i].setInitialCondition(mouseX,mouseY,vx, vy, angle);
	
	}
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
