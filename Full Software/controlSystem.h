/* 
 * controlSystem.h declares the functions for the ControlSystem class
 */

#ifndef CONTROLSYSTEM_H_
#define CONTROLSYSTEM_H_

#include "PID.h"
#include <math.h>
#include <opencv2/opencv.hpp>

#define maxAng 45
#define reverseAng 180
#define headingScaling 60
#define positionP 80.7
#define positionI 0.00134
#define positionD 41.7
#define angleP 29.3
#define angleI 0.00203
#define angleD 50.7
#define positionVelP 47.8
#define positionVelI 0.00736
#define positionVelD 7.70
#define PI 3.14159265

class ControlSystem {
public:
    ControlSystem(float targetx, float targety);
	void setTarget(float targetx, float targety);
    void update(float position[], float velocity[], float heading, float deltaTime, float * responseAngle, float * responseForce);
private:
	float target[2];
	PID posController;
	PID angController;
	PID posVelController;
	int pP = int(positionP*10);
	int pI = int(positionI*100000);
	int pD = int(positionD * 10);
	int aP = int(angleP * 10);
	int aI = int(angleI * 100000);
	int aD = int(angleD * 10);
	int vP = int(positionVelP * 10);
	int vI = int(positionVelI * 100000);
	int vD = int(positionVelD * 10);
	float posResponse[2];
	float angResponse[2];
	float posVelResponse[2];
	float response[2];
	float backx;
	float backy;
	float backz;
	int powerOn;
};

#endif /* CONTROLSYSTEM_H_ */