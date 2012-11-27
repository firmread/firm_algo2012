#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
    ofEnableSmoothing();
	ofBackground(0,0,0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
    randomInitial = 500;
	int max = 4;
	for (int i = 0; i < max; i++){
		particle myParticle;
        
        // far apart start points to make a burst opening!
        int count = 1;
        int startx,starty;
        
        if (i%4==0) {
            startx = (100*count);
            starty = (100*count);
            count++;
        }
        if (i%4==1) {
            startx = (ofGetWidth() - 100*count);
            starty = (100*count);
            count++;
        }
        if (i%4==2) {
            startx = (ofGetWidth() - 100*count);
            starty = (ofGetHeight() - 100*count);
            count++;
        }
        if (i%4==3) {
            startx = (100*count);
            starty = (ofGetHeight() - 100*count);
            count++;
        }
        
		myParticle.setInitialCondition(startx,starty,0,0);
		particles.push_back(myParticle);
	}
	
	for (int i = 0; i < (particles.size()-1); i++){
		spring mySpring;
		mySpring.distance		= 25;
		mySpring.springiness	= 0.4f;
		mySpring.particleA = & (particles[i]);
		mySpring.particleB = & (particles[(i+1)%particles.size()]);
		springs.push_back(mySpring);
	}
	
	//particles[particles.size()-1].bFixed = true;
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
    
    //start delay to see bouncy jump start
    if (ofGetElapsedTimeMillis()>500) {
        for (int i = 0; i < particles.size(); i++){
            particles[i].resetForce();
        }
        
        
        for (int i = 0; i < particles.size(); i++){
            particles[i].addForce(0,0.3);
        }
         
        
        for (int i = 0; i < springs.size(); i++){
            springs[i].update();
        }
        
        
        for (int i = 0; i < particles.size(); i++){
            particles[i].addDampingForce();
            particles[i].update();
            particles[i].bounceOffWalls();
        }
        
        trail.push_back(particles[particles.size()-1].pos);
        if (trail.size() > 30){
            trail.erase(trail.begin());
        }
        
        //let's get lazy ass plankton jumping
        
        if (particles[particles.size()-1].pos.y == ofGetHeight()) {
            if (ofGetSeconds()%5 == 0) {
                // reposition everything:
                        for (int i = 0; i < particles.size(); i++){
                            // far apart start points to make a burst opening!
                            int count = 1;
                            int startx,starty;
                            
                            if (i%4==0) {
                                startx = (ofRandom(randomInitial)*count);
                                starty = (10*count);
                                count++;
                            }
                            if (i%4==1) {
                                startx = (ofGetWidth() - ofRandom(randomInitial)*count);
                                starty = (10*count);
                                count++;
                            }
                            if (i%4==2) {
                                startx = (ofGetWidth() - ofRandom(randomInitial)*count);
                                starty = (ofGetHeight() - ofRandom(randomInitial)*count);
                                count++;
                            }
                            if (i%4==3) {
                                startx = (10*count);
                                starty = (ofGetHeight() - ofRandom(randomInitial)*count);
                                count++;
                            }
                            
                            particles[i].setInitialCondition(startx,starty,0,0);
                        }
            }
        }
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
	

	ofSetColor(0xffffff);
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].draw();
	}
	
	ofNoFill();
	ofBeginShape();
	for (int i = 0; i < trail.size(); i++){
		ofVertex(trail[i].x, trail[i].y);
	}
	ofEndShape();

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	switch (key){
			
		case ' ':
			// reposition everything: 
			for (int i = 0; i < particles.size(); i++){
                // far apart start points to make a burst opening!
                int count = 1;
                int startx,starty;
                
                if (i%4==0) {
                    startx = (ofRandom(randomInitial)*count);
                    starty = (10*count);
                    count++;
                }
                if (i%4==1) {
                    startx = (ofGetWidth() - ofRandom(randomInitial)*count);
                    starty = (10*count);
                    count++;
                }
                if (i%4==2) {
                    startx = (ofGetWidth() - ofRandom(randomInitial)*count);
                    starty = (ofGetHeight() - ofRandom(randomInitial)*count);
                    count++;
                }
                if (i%4==3) {
                    startx = (10*count);
                    starty = (ofGetHeight() - ofRandom(randomInitial)*count);
                    count++;
                }
                
				particles[i].setInitialCondition(startx,starty,0,0);
			}
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
	particles[0].pos.set(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particles[0].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	particles[0].bFixed = false;
}

