// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef ANGLING_TOOL_H
#define ANGLING_TOOL_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

#define ANGLE_PID_P 2.0
#define ANGLE_PID_I 0.0
#define ANGLE_PID_D 0.0
#define ANGLE_PID_PERIOD 0.020

/**
 *
 *
 * @author ExampleAuthor
 */
class AnglingTool: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	AnalogChannel* anglePot;
	CANJaguar* liftLeadscrew;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	AnglingTool();
	void InitDefaultCommand();
	
	void setManualSpeed(float speed);
	
	/**
	 * Range -1 to 1
	 */
	float getAngle();
};
#endif
