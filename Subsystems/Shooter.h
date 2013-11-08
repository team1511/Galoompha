// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef SHOOTER_H
#define SHOOTER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
/**
 *
 *
 * @author ExampleAuthor
 */
class Shooter: public Subsystem {
// It's desirable that everything possible under private except
// for methods that implement subsystem capabilities
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	DigitalInput* loadSensor;
	CANJaguar* shooterWheel;
	Servo* kicker;
	Servo* blocker;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	Shooter();
	void InitDefaultCommand();
	
	bool holdsDisk();
	void block(bool doit);
	void kick(bool forward);
	void setTargetSpeed(float speed);
	bool atTargetSpeed();
	bool isLoaded();
};
#endif
