//
//  circleBg.cpp
//  w1-2_xeno
//
//  Created by Firm Read on 9/18/12.
//
//

#include "circleBg.h"
//------------------------------------------------------------------
void circleBg::setup(){
    pos.set(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()));
    innerRadius = ofRandom(20,100);
    outerRadius = innerRadius + ofRandom(20,300);

//    colorA.setHsb(ofRandom(0,60),255,255);
//    colorB.setHsb(ofRandom(0,255), 60,60);

    colorA.setHsb(140,255,255);
    colorB.setHsb(140, ofRandom(100),60);
    
}

//------------------------------------------------------------------
void circleBg::update(ofPoint mouse) {
	
    float distance = (pos - mouse).length();
    pct = (distance - innerRadius) / (outerRadius - innerRadius);
    pct = ofClamp(pct, 0,1);
}


//------------------------------------------------------------------
void circleBg::draw(){
    ofColor mix;
    mix.r = (1-pct) * colorA.r + (pct) * colorB.r;
    mix.g = (1-pct) * colorA.g + (pct) * colorB.g;
    mix.b = (1-pct) * colorA.b + (pct) * colorB.b;
    ofSetColor(mix);
    ofCircle(pos, innerRadius * (pct));
}