#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
	damping = 0.08f;
    size = 5;
    shape = 3;
    particleColor.set(200,100);
    prevPos.set(0, 0);
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
    
    //gradient
    float hue,sat,bri,ang,dist;
    ang = atan2(pos.y-ofGetHeight()/2,pos.x-ofGetWidth()/2)+PI;
    dist = ofDist(pos.x,pos.y,ofGetWidth()/2,ofGetHeight()/2);
    hue = ang/TWO_PI*255;
    sat = ofMap(dist,0,ofGetWidth()/4,100,255,true);
    bri = ofMap(dist,ofGetWidth()/4,ofGetWidth()/2,255,150,true);
    particleColor = ofColor::fromHsb(hue,sat,bri);
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
    
    ofSetColor(255,100);
	ofPoint temp;
	temp.x = pos.x;
	temp.y = pos.y;
	points.push_back(temp);
	if (points.size() > 20){
		points.erase(points.begin());
	}
    
	ofNoFill();
    
    ofSetColor(particleColor,100);
	ofBeginShape();
	for (int i = 0; i < points.size(); i++){
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape();
   
    //
    float dx = pos.x - prevPos.x;
    float dy = pos.y - prevPos.y;
    
    angle = atan2(dy, dx);
    
    prevPos.x = pos.x;
    prevPos.y = pos.y;
    
    
    ofFill();
    ofSetCircleResolution(shape);
    ofPushMatrix();
        ofTranslate(pos.x, pos.y);
        ofRotateZ(angle * RAD_TO_DEG);
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
