#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "particle.h"
#include "spring.h"
#include "silkworm.h"

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
	
        // PDF
        
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
        
        vector <ofRectangle> dropZoneRects;
        vector <ofImage> images;
        
        ofTrueTypeFont font;
        
        bool						oneShot;
        bool						pdfRendering;
    
    
        silkworm worm, worming;
	
};

#endif
	
