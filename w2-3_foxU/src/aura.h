//
//  aura.h
//  w2-3_foxU
//
//  Created by Firm Read on 9/25/12.
//
//

#ifndef __w2_3_foxU__aura__
#define __w2_3_foxU__aura__

#include <iostream>
#include "ofMain.h"
class aura {
public:
    
    void draw(int inX, int inY, int alpha);
    void update(int inX, int inY);
    
    float dx,dy,angle;
    ofPoint pos, prevPos;
};

#endif /* defined(__w2_3_foxU__aura__) */
