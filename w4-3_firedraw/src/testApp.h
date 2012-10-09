#ifndef _TEST_APP
#define _TEST_APP
#define NUM_FIRE 2


#include "ofMain.h"
#include "fireworks.h"
#include "particle.h"

class testApp : public ofSimpleApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed  (int key);
		void keyReleased (int key);
		
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();
		
        fireworks firing[NUM_FIRE];
        int check;
	
};

#endif
	
