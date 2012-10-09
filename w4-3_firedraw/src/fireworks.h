//
//  fireworks.h
//  w4-3_complicating_fireworks
//
//  Created by Firm Read on 10/8/12.
//
//

#ifndef __w4_3_complicating_fireworks__fireworks__
#define __w4_3_complicating_fireworks__fireworks__

#include <iostream>
#include "ofMain.h"
#include "particle.h"

class fireworks{
public:
    void setup();
    void update();
    void draw();
    void refire(int x, int y);
    
    
    vector <particle> particles;
};



#endif /* defined(__w4_3_complicating_fireworks__fireworks__) */
