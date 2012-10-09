#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
	damping = 0.01f;
}

//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void particle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void particle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity 
	// damping is a force operating in the oposite direction of the 
	// velocity vector
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
}

//------------------------------------------------------------
void particle::update(){	
	vel = vel + frc;
	pos = pos + vel;
}

//------------------------------------------------------------
void particle::draw(){
    // polygon > circle
    if (shape>6) {
        shape = 100;
    }
    
    
	ofPoint temp;
	temp.x = pos.x;
	temp.y = pos.y;
	points.push_back(temp);
	if (points.size() > 20){
		points.erase(points.begin());
	}
    
	ofNoFill();
    ofSetColor(particleColor);
	ofBeginShape();
	for (int i = 0; i < points.size(); i++){
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape();
    
    ofFill();
    ofSetCircleResolution(shape);
    ofPushMatrix();
        ofTranslate(pos.x, pos.y);
        ofRotate(angle + ofGetElapsedTimef()*angle);
        ofCircle(0, 0, size);
    ofPopMatrix();
    ofSetCircleResolution(100);
}

