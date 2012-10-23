#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "particle.h"
#include "vectorField.h"
#include "fft.h"
#include "fftOctaveAnalyzer.h"

#define BUFFER_SIZE 512

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
        void audioIn (float * input, int bufferSize, int nChannels);
    
		// let's make a vector of them
		vector <particle> particles;
		vectorField VF;
	
		int drawingStyle;
		bool bFade,moveleft,moveright;
    
    
    FFTOctaveAnalyzer FFTanalyzer;
	
    private:
        //distinglish from ones on the FFT folder
        float * left;
        float * right;
        int bufferCounter;
        fft myfft;
        
        float magnitude [BUFFER_SIZE];
        float phase [BUFFER_SIZE];
        float power [BUFFER_SIZE];
        float freq [BUFFER_SIZE];
    
        float smoothedVol;
        float scaledVol;
};

#endif

