//
//  fox.h
//  emptyExample
//
//  Created by Firm Read on 9/25/12.
//
//

#ifndef __emptyExample__fox__
#define __emptyExample__fox__

#include <iostream>
#include "ofMain.h"

class fox {
public:
    void setup(int posx, int posy, float speed);
    void draw(float inX, float inY);
    void xenoToPoint(float inX, float inY);
    
    ofColor fill, stroke;
    
    ofPoint pos;
    ofPoint prevPos;
    
    float angle, dx, dy;
    float catchSpeed;
    int lineW,eyeW;
};

#endif /* defined(__emptyExample__fox__) */
