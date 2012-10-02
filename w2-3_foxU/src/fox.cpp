//
//  fox.cpp
//  emptyExample
//
//  Created by Firm Read on 9/25/12.
//
//

#include "fox.h"

//------------------------------------------------------------------

void fox::setup(int posx, int posy, float speed){
    catchSpeed = speed;
    pos.set(posx, posy);
    prevPos.set(posx, posy);
    
    fill.set (245, 148, 67);
    stroke.set(126, 69, 22);
    
    lineW = 3;
    eyeW = 6;
}

////------------------------------------------------------------------
//
//void fox::draw(float inX, float inY){
//    
//    ofPushMatrix();
//        ofTranslate(pos.x, pos.y, 0);
//        ofRotateZ(angle * RAD_TO_DEG);
//        
//        ofScale(0.5, 0.5);
//
//        if(inX > pos.x){
//            
//            ofPushMatrix();
//            ofTranslate(60, 85);
//                //tail
//                
//                ofPushMatrix();
//                ofTranslate(-dx*2, -dy*2);
//            if(ofGetElapsedTimeMillis()%2000 < 200)
//                        ofRotateZ(3 * sin(ofGetElapsedTimeMillis()/3));
//                    ofFill();
//                    ofBeginShape();
//                        ofCurve(-100,-100,-155, -88, -237, -106, -250, -150);
//                        ofSetColor(fill);
//                        ofCurve(-200,-200,-155, -88, -237, -106, -350, -250);
//                    ofEndShape();
//                    //
//                    ofNoFill();
//                    ofSetColor(stroke);
//                    ofSetLineWidth(lineW);
//                    ofBeginShape();
//                        ofLine( -155, -88, -237, -106);
//                        ofCurve(-200,-200,-155, -88, -237, -106, -350, -250);
//                    ofEndShape();
//            
//                ofPopMatrix();
//            
//                //body
//                ofPushMatrix();
//                ofTranslate(-dx*2, -dy*2);
//                    ofFill();
//                    ofSetColor(fill);
//                    ofCircle(-120, -73, 60);
//                    //
//                    ofNoFill();
//                    ofSetColor(stroke);
//                    ofSetLineWidth(lineW);
//                    ofCircle(-120 , -73 , 60);
//                ofPopMatrix();
//            
//                
//                //face
//                ofFill();
//                ofSetColor(fill);
//                ofBeginShape();
//                    ofVertex(0, 0);
//                    ofVertex(-64, -218);
//                    ofVertex(-72, -114);
//                    ofVertex(-186, -194);
//                    ofVertex(-122, -90);
//                    ofVertex(0, 0);
//                ofEndShape();
//                //
//                ofNoFill();
//                ofSetColor(stroke);
//                ofSetLineWidth(lineW);
//                
//                ofBeginShape();
//                    ofVertex(0, 0);
//                    ofVertex(-64, -218);
//                    ofVertex(-72, -114);
//                    ofVertex(-186, -194);
//                    ofVertex(-122, -90);
//                    ofVertex(0, 0);
//                ofEndShape();
//                
//                ofSetLineWidth(eyeW);
//                ofLine(-112, -70, -66, -75);
//                ofLine(-41, -84, -14, -103);
//            ofPopMatrix();
//        }
//    
//    
//        else
//        {
//            
//            ofPushMatrix();
//            ofTranslate(60, -85);
//                
//                //tail
//            
//                ofPushMatrix();
//                ofTranslate(dx*2, -dy*2);
//                if(ofGetElapsedTimeMillis()%2000 < 200)
//                        ofRotateZ(3 * sin(ofGetElapsedTimeMillis()/3));
//                    ofFill();
//                    ofBeginShape();
//                    ofCurve(-100,100,-155, 88, -237, 106, -250, 150);
//                    ofSetColor(fill);
//                    ofCurve(-200,200,-155, 88, -237, 106, -350, 250);
//                    ofEndShape();
//                    //
//                    ofNoFill();
//                    ofSetColor(stroke);
//                    ofSetLineWidth(lineW);
//                    ofBeginShape();
//                    ofLine( -155, 88, -237, 106);
//                    ofCurve(-200,200,-155, 88, -237, 106, -350, 250);
//                    ofEndShape();
//                ofPopMatrix();
//            
//                //body
//            
//                ofPushMatrix();
//                ofTranslate(dx*2, -dy*2);
//                    ofFill();
//                    ofSetColor(fill);
//                    ofCircle(-120, 73, 60);
//                    //
//                    ofNoFill();
//                    ofSetColor(stroke);
//                    ofSetLineWidth(lineW);
//                    ofCircle(-120, 73, 60);
//                ofPopMatrix();
//            
//                //face
//                ofFill();
//                ofSetColor(fill);
//                ofBeginShape();
//                ofVertex(0, 0);
//                ofVertex(-64, 218);
//                ofVertex(-72, 114);
//                ofVertex(-186, 194);
//                ofVertex(-122, 90);
//                ofVertex(0, 0);
//                ofEndShape();
//                //
//                ofNoFill();
//                ofSetColor(stroke);
//                ofSetLineWidth(lineW);
//                
//                ofBeginShape();
//                ofVertex(0, 0);
//                ofVertex(-64, 218);
//                ofVertex(-72, 114);
//                ofVertex(-186, 194);
//                ofVertex(-122, 90);
//                ofVertex(0, 0);
//                ofEndShape();
//                
//                ofSetLineWidth(eyeW);
//                ofLine(-112, 70, -66, 75);
//                ofLine(-41, 84, -14, 103);
//            ofPopMatrix();
//        }
//    
//    
//    ofPopMatrix();
//}



void fox::draw(float inX, float inY){
    
    ofPushMatrix();
    ofTranslate(pos.x, pos.y, 0);
    ofRotateZ(angle * RAD_TO_DEG);
    
    ofScale(0.5, 0.5);
    
    if(inX > pos.x){
        ofScale(1,1);
    } else {
        ofScale(1,-1);
    }
    
        ofPushMatrix();
        ofTranslate(60, 85);
        //tail
        
        ofPushMatrix();
        ofTranslate(-dx*2, -dy*2);
        if(ofGetElapsedTimeMillis()%2000 < 200)
            ofRotateZ(3 * sin(ofGetElapsedTimeMillis()/3));
        ofFill();
        ofBeginShape();
        ofCurve(-100,-100,-155, -88, -237, -106, -250, -150);
        ofSetColor(fill);
        ofCurve(-200,-200,-155, -88, -237, -106, -350, -250);
        ofEndShape();
        //
        ofNoFill();
        ofSetColor(stroke);
        ofSetLineWidth(lineW);
        ofBeginShape();
        ofLine( -155, -88, -237, -106);
        ofCurve(-200,-200,-155, -88, -237, -106, -350, -250);
        ofEndShape();
        
        ofPopMatrix();
        
        //body
        ofPushMatrix();
        ofTranslate(-dx*2, -dy*2);
        ofFill();
        ofSetColor(fill);
        ofCircle(-120, -73, 60);
        //
        ofNoFill();
        ofSetColor(stroke);
        ofSetLineWidth(lineW);
        ofCircle(-120 , -73 , 60);
        ofPopMatrix();
        
        
        //face
        ofFill();
        ofSetColor(fill);
        ofBeginShape();
        ofVertex(0, 0);
        ofVertex(-64, -218);
        ofVertex(-72, -114);
        ofVertex(-186, -194);
        ofVertex(-122, -90);
        ofVertex(0, 0);
        ofEndShape();
        //
        ofNoFill();
        ofSetColor(stroke);
        ofSetLineWidth(lineW);
        
        ofBeginShape();
        ofVertex(0, 0);
        ofVertex(-64, -218);
        ofVertex(-72, -114);
        ofVertex(-186, -194);
        ofVertex(-122, -90);
        ofVertex(0, 0);
        ofEndShape();
        
        ofSetLineWidth(eyeW);
        ofLine(-112, -70, -66, -75);
        ofLine(-41, -84, -14, -103);
        ofPopMatrix();

    
   
    
    
    ofPopMatrix();
}

//------------------------------------------------------------------

void fox::xenoToPoint(float inX, float inY){
    
    pos.x = catchSpeed * inX + (1-catchSpeed) * pos.x;
    pos.y = catchSpeed * inY + (1-catchSpeed) * pos.y;
    
    dx = pos.x - prevPos.x;
    dy = pos.y - prevPos.y;
    
    angle = atan2(dy,dx);
    
    prevPos.x = pos.x;
    prevPos.y = pos.y;
    
}

//------------------------------------------------------------------