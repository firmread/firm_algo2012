#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
//    ofEnableSmoothing();
    ofEnableAlphaBlending();
	ofBackground(0,0,0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
    ofSetWindowShape(1200, 500);
	
    randomInitial = 700;
	int max = 7;
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
	
    spring mySpring;

    
    //shape line
    mySpring.distance		= 25;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[0]);
    mySpring.particleB = & (particles[1]);
    springs.push_back(mySpring);
    
    mySpring.distance		= 25;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[1]);
    mySpring.particleB = & (particles[2]);
    springs.push_back(mySpring);

    mySpring.distance		= 25;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[2]);
    mySpring.particleB = & (particles[3]);
    springs.push_back(mySpring);
    
    mySpring.distance		= 25;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[3]);
    mySpring.particleB = & (particles[4]);
    springs.push_back(mySpring);
    
    mySpring.distance		= 25;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[4]);
    mySpring.particleB = & (particles[5]);
    springs.push_back(mySpring);
    
    mySpring.distance		= 25;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[5]);
    mySpring.particleB = & (particles[0]);
    springs.push_back(mySpring);
    
    //tail line
    mySpring.distance		= 100;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[5]);
    mySpring.particleB = & (particles[6]);
    springs.push_back(mySpring);

    
    //diagnal line
	mySpring.distance		= 100;
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[0]);
	mySpring.particleB = & (particles[3]);
	springs.push_back(mySpring);
	
	mySpring.distance		= 100;
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[1]);
	mySpring.particleB = & (particles[4]);
	springs.push_back(mySpring);
    
	mySpring.distance		= 100;
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[2]);
	mySpring.particleB = & (particles[5]);
	springs.push_back(mySpring);
	

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
    


        //draw spring
        ofEnableSmoothing();
        ofSetColor(0xffffff);
        for (int i = 0; i < particles.size(); i++){
            particles[i].draw();
        }
        for (int i = 0; i < springs.size(); i++){
            springs[i].draw();
        }
        
        ofNoFill();
        ofSetColor(255);
        ofBeginShape();
        for (int i = 0; i < trail.size(); i++){
            ofCurveVertex(trail[i].x, trail[i].y);
        }
        ofEndShape();
        ofDisableSmoothing();
    ofPopMatrix();

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
	particles[2].pos.set(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particles[2].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	particles[2].bFixed = false;
}

