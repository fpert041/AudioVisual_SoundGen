#include "maximilian.h"

//This shows how the fundamental building block of digital audio - the sine wave.

unsigned int sampR = maxiSettings::sampleRate;

vector<maxiOsc> myOscBand(4); // a vector of oscillators - can be called anything. Can be any of the available waveforms.
vector<maxiOsc> myLFOs(3);
int t = 0; // time (expressed in 1/samp_rate seconds) -> usually 1/44100
double osc1(int t);
double osc2(int t);


void setup() {//some inits
    //nothing to go here this time
}

void play(double *output) {
    
    if(t>sampR) t=0; //reset time counter each second
    
    //double amp1 = 0.8; //sin(t/(sampR);
    
    
    double mixL = osc1(t)*0.0;
    double mixR = osc2(t)*0.9;

    output[0]= mixL;
    output[1]= mixR;
    
    t++;
 
//    string s = to_string(freq2);
//    s.append("\n");
//    const char * c = s.c_str();
//    printf(c);
}

double osc1(int t){
    

    double freq2 = 100.0 - 50.0 * t/(sampR*4.);
    double freq3 = 1000 - (900 * myLFOs[1].phasor(0.1));
    
    double rawSample = (myOscBand[1].sinewave(40 + myOscBand[0].sinewave(20) * freq3)) * myOscBand[1].square( freq2) + myOscBand[2].noise()*0.2 + myOscBand[3].phasor(100);
    
    
    rawSample *=  0.9 * myLFOs[0].coswave(1)/2+0.5;
    
    return rawSample;
    
}

double osc2(int t){
    
    
    double freq2 = 100.0 - 50.0 * t/(sampR*4.);
    double freq3 = (900 * myLFOs[1].phasor(0.1));
    
    double rawSample = (myOscBand[1].sinewave(40 + myOscBand[0].sinewave(20) * freq3)) * myOscBand[1].square( freq2) + myOscBand[2].noise()*0.2 + myOscBand[3].square(30);
    
    
    rawSample *=  0.9 * myLFOs[0].coswave(6)/2+0.5;
    
    return rawSample;

    
}

