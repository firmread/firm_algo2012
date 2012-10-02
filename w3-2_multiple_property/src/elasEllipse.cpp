//
//  elasEllipse.cpp
//  w3-2_multiple_property
//
//  Created by Firm Read on 10/2/12.
//
//

#include "elasEllipse.h"

void elasEllipse::draw(int x, int y, ofColor c, float vel, float angle){
    
    ofFill();
    ofSetColor(c);
    
    ofPushMatrix();
        ofTranslate(x, y, 0);
        ofRotateZ(angle * RAD_TO_DEG);
    
        ofEllipse(0, 0, 40 + vel/7.0, 40 -vel/30.0);
        ofNoFill();
        ofSetColor(255);
        ofEllipse(0, 0, 40 + vel/7.0, 40 -vel/30.0);
    ofPopMatrix();
}