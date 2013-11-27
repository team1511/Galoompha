#ifndef ANGLING_TOOL_H
#define ANGLING_TOOL_H

#include "WPILib.h"

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
