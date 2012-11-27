//
//  silkworm.h
//  w8-2_silkwormlady
//
//  Created by Firm Read on 11/27/12.
//
//

#ifndef __w8_2_silkwormlady__silkworm__
#define __w8_2_silkwormlady__silkworm__

#include <iostream>
#include "ofMain.h"
#include "particle.h"
#include "spring.h"


class silkworm
{
	
public:
    
    void setup();
    void resetForce();
    void gravity();
    void update();
    void draw();
    void resetPosition();
    void moveToPoint(int x, int y);
    void fixHead();
    void releaseHead();
    
    
    vector <particle> particles;
    vector <spring> springs;
	
	
    vector < ofPoint > trail;
	
    int randomInitial;
    float skinLength1, skinLength2;
	
};



#endif /* defined(__w8_2_silkwormlady__silkworm__) */
