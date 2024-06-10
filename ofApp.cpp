#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(0);
	ofSetLineWidth(1.5);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto radius = 50;
	for (int y = -280; y <= 280; y += 140) {

		auto deg_param = 120;
		auto deg_start = ofMap(y, -280, 280, 0, 360);

		for (int deg = deg_start; deg < deg_start + 200; deg += 20) {

			vector<glm::vec2> vertices;
			auto tmp_deg = deg + ofGetFrameNum() * 3;

			for (int x = -220; x <= 220; x += 220) {

				auto vertex = glm::vec2(x + radius * cos(tmp_deg * DEG_TO_RAD), y + radius * sin(tmp_deg * DEG_TO_RAD));
				vertices.push_back(vertex);
				tmp_deg += deg_param;
			}

			ofNoFill();
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape();

			for (auto& vertex : vertices) {

				ofFill();
				ofDrawCircle(vertex, 2);

				ofNoFill();
				ofDrawCircle(vertex, 5);
			}
		}
	}

	/*
	int start = 50;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}