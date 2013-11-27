#ifndef ANGLING_TOOL_H
#define ANGLING_TOOL_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#define ANGLE_PID_P 2.0
#define ANGLE_PID_I 0.0
#define ANGLE_PID_D 0.0
#define ANGLE_PID_PERIOD 0.020

class AnglingTool: public Subsystem {
private:
	AnalogChannel* anglePot;
	CANJaguar* liftLeadscrew;
public:
	AnglingTool();
	void InitDefaultCommand();
	void setSpeed(float speed);
	
	/**
	 * Range -1 to 1
	 */
	float getAngle();
};
#endif
