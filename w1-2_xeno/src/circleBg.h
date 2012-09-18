//
//  circleBg.h
//  w1-2_xeno
//
//  Created by Firm Read on 9/18/12.
//
//

#ifndef __w1_2_xeno__circleBg__
#define __w1_2_xeno__circleBg__

#include <iostream>
#include "ofMain.h"

class circleBg {
    
public:
    
    void setup();
    void update(ofPoint mouse);
    void draw();
    
    float innerRadius;
    float outerRadius;
    ofPoint pos;
    ofColor colorA;
    ofColor colorB;
    float pct;
};

#endif /* defined(__w1_2_xeno__circleBg__) */
