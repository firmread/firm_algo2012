//
//  aura.cpp
//  w2-3_foxU
//
//  Created by Firm Read on 9/25/12.
//
//


#include "aura.h"

void aura::update(int inX, int inY){

    dx = inX - prevPos.x;
    dy = inY - prevPos.y;

    angle = atan2(dy,dx);

    prevPos.x = inX;
    prevPos.y = inY;
}

void aura::draw(int inX, int inY, int alpha){
	
    ofPushMatrix();
    ofTranslate(inX, inY);
    float sc = ofMap(sin(ofGetElapsedTimef()/3),-1,1,0.05, 0.2);
    ofScale(sc, sc);
    
//    ofRotateZ(angle*RAD_TO_DEG);
    
	float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;
	
    ofSetColor(41,171,226,alpha);
    
    for (int i = 0; i < 200; i++){
		float radius = 10 + i * 2;
		float angle = ofGetElapsedTimef() * (1 + i / 30.0);
		float x = xorig + radius * cos(angle);
		float y = yorig + radius * -sin(angle);
        ofPushMatrix();
        
        //xeno+ramdom+rotate
        
//        float catchUpSpeed = ofMap(inX, 0, ofGetWidth(), 0.001f, 2.0f,true);
        float catchUpSpeed = ofMap(sin(ofGetElapsedTimef()),-1,1,0.001f, 2.0f);
        cout << catchUpSpeed << endl;
        int randomized = catchUpSpeed * ofRandom(1.0) + (1-catchUpSpeed) * randomized;
        ofRotate(randomized * sin(angle));
        ofCircle(x, y, 10 * sin(angle)+cos(-angle));
        ofPopMatrix();
	}
    ofPopMatrix();
    
}