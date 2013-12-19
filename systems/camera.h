#ifndef SYSTEMS_CAMERA_H_
#define SYSTEMS_CAMERA_H_

#include "WPILib.h"

class CameraTilter: public Subsystem {
public:
	CameraTilter();
	void InitDefaultCommand();
	void tiltToAngle(double angle);
	double getAngle();
private:
	Servo* servo;
};

#endif // SYSTEMS_CAMERA_H_
