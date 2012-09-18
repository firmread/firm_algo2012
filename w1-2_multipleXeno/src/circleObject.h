//
//  circleObject.h
//  w1-2_xeno
//
//  Created by Firm Read on 9/18/12.
//
//

#ifndef __w1_2_xeno__circleObject__
#define __w1_2_xeno__circleObject__

#include <iostream>
#include "ofMain.h"

class circleObject {
    
public:
	
    circleObject();
	
    void draw();
    void interpolateByPct(float myPct);
    void xenoToPoint(float catchX, float catchY);
    
    ofPoint		pos;
    ofPoint		posa;
    ofPoint		posb;
    float		pct;	// what pct are we between "a" and "b"
    float		shaper;
	
    float		catchUpSpeed;
    // take this pct of where I want to be, and 1-catchUpSpeed of my pos
	
    
};

#endif /* defined(__w1_2_xeno__circleObject__) */
