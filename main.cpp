#include "maximilian.h"

//This shows how the fundamental building block of digital audio - the sine wave.

vector<maxiOsc> myOscBand(4); // a vector of oscillators - can be called anything. Can be any of the available waveforms.
vector<maxiOsc> myLFOs(3);
int t = 0; // time (expressed in 1/samp_rate seconds) -> usually 1/44100

void setup() {//some inits
    //nothing to go here this time
}

void play(double *output) {
    
    unsigned int sampR = maxiSettings::sampleRate;
    
    if(t>sampR) t=0; //reset time counter each second
    
    double amp1 = 0.8; //sin(t/(sampR);
    
    double freq2 = 100.0 - 50.0 * t/(sampR*4.);
    
    double rawSample = (myOscBand[0].sinewave(440)*amp1 ) * myOscBand[1].square( freq2*0.8) + myOscBand[2].noise()*0.4 + myOscBand[3].phasor(220);
    
    
    rawSample *= myLFOs[0].coswave(2);
    
    output[0]= rawSample;
    output[1]=output[0];
    
    t++;
 
//    string s = to_string(freq2);
//    s.append("\n");
//    const char * c = s.c_str();
//    printf(c);
}

