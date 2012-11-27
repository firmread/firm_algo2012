#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(0,0,0);
    ofEnableAlphaBlending();
    
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
    ofSetWindowShape(1200, 500);
	
    randomInitial = 700;
	int shape = 6 + 1;
    int skin = 4 * 2;
	for (int i = 0; i < shape + skin; i++){
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
    springs.push_back(mySpring);        //[0] in springs vector
    
    
    //moving side 1
    mySpring.distance		= 25;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[1]);
    mySpring.particleB = & (particles[2]);
    springs.push_back(mySpring);        //1

    mySpring.distance		= 25;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[2]);
    mySpring.particleB = & (particles[14]);
    springs.push_back(mySpring);        //2
    
    mySpring.distance		= 25;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[14]);
    mySpring.particleB = & (particles[12]);
    springs.push_back(mySpring);        //3
    
    
    //moving side 2
    mySpring.distance		= 25;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[12]);
    mySpring.particleB = & (particles[13]);
    springs.push_back(mySpring);        //4
    
    mySpring.distance		= 25;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[13]);
    mySpring.particleB = & (particles[0]);
    springs.push_back(mySpring);        //5
    
    
    
    //diagnal line
    
	mySpring.distance		= 100;
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[1]);
	mySpring.particleB = & (particles[12]);
	springs.push_back(mySpring);        //6
	
	mySpring.distance		= 100;
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[2]);
	mySpring.particleB = & (particles[13]);
	springs.push_back(mySpring);        //7
    
    
    //main diagnal
	mySpring.distance		= 50;
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[0]);
	mySpring.particleB = & (particles[14]);
	springs.push_back(mySpring);        //8
    
    
    
    //tail line
    
    mySpring.distance		= 50;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[14]);
    mySpring.particleB = & (particles[7]);
    springs.push_back(mySpring);        //9

    //head to tail structure
    mySpring.distance		= 200;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[0]);
    mySpring.particleB = & (particles[7]);
    springs.push_back(mySpring);        //10
    
    
    
    skinLength1 = 1;
    skinLength2 = 1;
    //tail skin side 1
    
    mySpring.distance		= skinLength1;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[2]);
    mySpring.particleB = & (particles[3]);
    springs.push_back(mySpring);        //11
    
    mySpring.distance		= skinLength1;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[3]);
    mySpring.particleB = & (particles[4]);
    springs.push_back(mySpring);        //12
    
    mySpring.distance		= skinLength1;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[4]);
    mySpring.particleB = & (particles[5]);
    springs.push_back(mySpring);        //13
    
    mySpring.distance		= skinLength1;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[5]);
    mySpring.particleB = & (particles[6]);
    springs.push_back(mySpring);        //14
    
    mySpring.distance		= skinLength1;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[6]);
    mySpring.particleB = & (particles[7]);
    springs.push_back(mySpring);        //15
    
    
    //tail skin side 2
    
    mySpring.distance		= skinLength2;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[7]);
    mySpring.particleB = & (particles[8]);
    springs.push_back(mySpring);        //16
    
    mySpring.distance		= skinLength2;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[8]);
    mySpring.particleB = & (particles[9]);
    springs.push_back(mySpring);        //17
    
    mySpring.distance		= skinLength2;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[9]);
    mySpring.particleB = & (particles[10]);
    springs.push_back(mySpring);        //18
    
    mySpring.distance		= skinLength2;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[10]);
    mySpring.particleB = & (particles[11]);
    springs.push_back(mySpring);        //19
    
    mySpring.distance		= skinLength2;
    mySpring.springiness	= 0.4f;
    mySpring.particleA = & (particles[11]);
    mySpring.particleB = & (particles[12]);
    springs.push_back(mySpring);        //20
    
    
    //additional diagnal line
	mySpring.distance		= 80;
	mySpring.springiness	= 0.2f;
	mySpring.particleA = & (particles[1]);
	mySpring.particleB = & (particles[13]);
	springs.push_back(mySpring);        //21

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
    if (ofGetElapsedTimeMillis()>250) {
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
        
        trail.push_back(particles[6].pos);
        if (trail.size() > 30){
            trail.erase(trail.begin());
        }
        
        //let's get lazy ass plankton jumping
        
        if (particles[7].pos.y == ofGetHeight()) {
            if (ofGetSeconds()%15 == 0) {
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
        
        // dance baby, dance!
        // gimme some sine wave
        springs[1].distance		= 25 +  50*sin(ofGetElapsedTimef()*10);
        springs[4].distance		= 25 +  50*sin(ofGetElapsedTimef()*10+ PI);
        
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
        ofSetColor(255,200);
        ofFill();
    
        for (int i = 0; i < particles.size(); i++){
            particles[i].draw();
        }
        
        ofBeginShape();
    
            ofCurveVertex(particles[0].pos.x, particles[0].pos.y);
            for (int i = 0; i < particles.size()-1; i++){
                ofCurveVertex(particles[i].pos.x, particles[i].pos.y);
            }
            ofCurveVertex(particles[0].pos.x, particles[0].pos.y);
        ofEndShape();
        for (int i = 0; i < springs.size(); i++){
            springs[i].draw();
        }
        
        ofNoFill();
        ofSetColor(255,50);
        ofSetLineWidth(3);
        ofBeginShape();
        for (int i = 0; i < trail.size(); i++){
            ofCurveVertex(trail[i].x, trail[i].y);
        }
        ofEndShape();
        ofSetLineWidth(1);
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

