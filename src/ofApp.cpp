#include "ofApp.h"
#include "DspFaust.h"

DspFaust* dspFaust = new DspFaust(48000, 8);

// ffmpeg -video_size 1024x768 -framerate 60 -f x11grab -i :1  -f pulse -ac 2 -i default output.mkv
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(120);
    ofSetBackgroundColor(0, 0, 0);
    ofEnableAntiAliasing();
    dspFaust->start(); 

    playhead = 0; 

    //dspFaust->setParamValue("/automata/MIX", 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    direction += 10; 
    playhead = 450 + abs(((direction + 660) % (660 * 2)) - 660); 
    //ofLog() << "playhead: " << playhead;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetHexColor(0xffffff);
	for (int i = 0; i < 6; i++){
		ofDrawLine(100,660/(i+1)+400,2160-100,660/(i+1)+400);
        while (playhead == 660/(i+1)+400) {
            dspFaust->setParamValue("/automata/harmGroup/master", playhead);
            playhead += 1;
        } 
    }
    ofDrawCircle(2160/2, playhead, 10);
} 

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
