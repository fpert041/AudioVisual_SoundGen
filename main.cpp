#include "maximilian.h"

//This shows how the fundamental building block of digital audio - the sine wave.

unsigned int sampR = maxiSettings::sampleRate;

vector<maxiOsc> myOscBand(11); // a vector of oscillators - can be called anything. Can be any of the available waveforms.
vector<maxiOsc> myLFOs(7);


int t = 0; // time (expressed in 1/samp_rate seconds) -> usually 1/44100
double osc1(int t);
double osc2(int t);


void setup() {//some inits
    //nothing to go here this time
}

void play(double *output) {
    
    if(t>sampR) t=0; //reset time counter each second
    
    //double amp1 = 0.8; //sin(t/(sampR);
    
    double main = 0.7 - 0.4*(myLFOs[4].sinewave(0.2)*0.5 + 0.5);
    double second = 1 - main;
    
    double freqTone = 140 + 1400*pow(myLFOs[5].sinewave(0.003)*0.5 + 0.5, 6);
    
    double tone = myOscBand[10].sinewave(freqTone) * (myLFOs[6].sinewave(1)*0.5 + 0.5);
    
    double mixL = osc1(t)*main + osc2(t)*second + tone*0.7;
    double mixR = osc1(t)*second + osc2(t)*main + tone*0.7;
    
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
    
    double rawSample = (myOscBand[1].sinewave(40 + myOscBand[0].sinewave(20) * freq3)) * myOscBand[4].square( freq2) + myOscBand[2].noise()*0.2 + myOscBand[3].phasor(100);
    
    
    rawSample *=  0.9 * myLFOs[0].coswave(1)/2+0.5;
    
    return rawSample;
    
}

double osc2(int t){
    
    
    double freq2 = 100.0 - 50.0 * t/(sampR*4.);
    double freq3 = (900 * myLFOs[2].phasor(0.1));
    
    double rawSample = (myOscBand[5].sinewave(40 + myOscBand[6].sinewave(20) * freq3)) * myOscBand[7].square( freq2) + myOscBand[8].noise()*0.2 + myOscBand[9].square(30);
    
    
    rawSample *=  0.9 * myLFOs[3].coswave(6)/2+0.5;
    
    return rawSample;

    
}

