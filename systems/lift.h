#ifndef ANGLING_TOOL_H
#define ANGLING_TOOL_H

#include "WPILib.h"

class AnglingTool: public Subsystem {
public:
	AnglingTool();
	void InitDefaultCommand();

	void setSpeed(double speed);

	double getAngle();
	double getSpeed();
	double getCurrent();
private:
	AnalogChannel* anglePot;
	CANJaguar* liftLeadscrew;
	double speed;
};
#endif
