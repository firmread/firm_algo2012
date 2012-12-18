//
//  fireworks.cpp
//  w4-3_complicating_fireworks
//
//  Created by Firm Read on 10/8/12.
//
//

#include "fireworks.h"

void fireworks::setup(){
    int basePoint = ofRandom(235);
    int eachr = ofRandom(5,20);
	for (int i = 0; i < 100; i++){
		particle myParticle;
        float r = ofRandom(-eachr,eachr);
        float angle = ofRandom(180);
		float vx = r*cos(angle);
		float vy = r*sin(angle);
        
        ofColor c;
        c.setHsb(basePoint + ofRandom(30), 200, 255,100);
        myParticle.particleColor = c;
        
        myParticle.shape = ofRandom(3,8);
        myParticle.size = abs(r)*2.2;
        myParticle.angle = angle;
        
		myParticle.setInitialCondition(300,300,vx, vy);
        
		myParticle.damping = ofRandom(0.01, 0.05);
		particles.push_back(myParticle);
	}
}


//========================================================================

void fireworks::update(){
    // on every frame
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		particles[i].addForce(0,0.25);  // gravity
		particles[i].addDampingForce();
		particles[i].update();
	}
    
    
}
//========================================================================

void fireworks::draw(){
    for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
    
}
//========================================================================

void fireworks::refire(int x, int y){
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
        particles[i].angle = angle;
        
		particles[i].setInitialCondition(x,y,vx, vy);
        
	}
    
}