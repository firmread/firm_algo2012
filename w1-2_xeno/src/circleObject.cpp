//
//  circleObject.cpp
//  w1-2_xeno
//
//  Created by Firm Read on 9/18/12.
//
//

#include "circleObject.h"


//------------------------------------------------------------------
circleObject::circleObject(){
	shaper = 1.0;
	catchUpSpeed = 0.1f;
    
}

//------------------------------------------------------------------
void circleObject::draw() {

    ofFill();
    //ofSetColor(ofRandom(100,255));
    ofCircle(pos.x, pos.y, 20);
}


//------------------------------------------------------------------
void circleObject::interpolateByPct(float myPct){
	pct = powf(myPct, shaper);
	pos.x = (1-pct) * posa.x + (pct) * posb.x;
	pos.y = (1-pct) * posa.y + (pct) * posb.y;
}

//------------------------------------------------------------------
void circleObject::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}
