#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
	damping = 0.08f;
    size = 5;
    shape = 3;
    particleColor.set(200,100);
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
//    ofCircle(pos.x, pos.y, 3);

    // polygon > circle
    if (shape>6) {
        shape = 15;
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
    ofSetCircleResolution(60);
}


//------------------------------------------------------------
void particle::bounceOffWalls(){
	
	// sometimes it makes sense to damped, when we hit
	bool bDampedOnCollision = true;
	bool bDidICollide = false;
	
	// what are the walls
	float minx = 0;
	float miny = 0;
	float maxx = ofGetWidth();
	float maxy = ofGetHeight();
	
	if (pos.x > maxx){
		pos.x = maxx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	} else if (pos.x < minx){
		pos.x = minx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	}
	
	if (pos.y > maxy){
		pos.y = maxy; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	} else if (pos.y < miny){
		pos.y = miny; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	}
	
	if (bDidICollide == true && bDampedOnCollision == true){
		vel *= 0.3;
	}
	
}

//------------------------------------------------------------
void particle::cleartail(){
    points.clear();
}
