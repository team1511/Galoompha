#ifndef CONTROLS_H
#define CONTROLS_H
#include "WPILib.h"

class OI {
public:
	OI();

	double getLeftDrivePower();
	double getRightDrivePower();
	double getSpeedSliderValue();
	double getAngleSliderValue();
	double getIndexManualPower();
	double getClimberPower();

	bool getClimberLimitsBroken();
	bool getContinuousShooting();
	bool getDriveOnVoltage();
private:
	Joystick leftDrive;
	Joystick rightDrive;
	Joystick auxStick;
	Joystick virtualStick;
	
	JoystickButton indexBroken;
	JoystickButton wheelEncBroken;
	JoystickButton angleBroken;
	JoystickButton voltageDriveMode;
	JoystickButton coastMode;
	JoystickButton climberLimitsBroken;
	JoystickButton continuousShooting;

	JoystickButton shoot;
	JoystickButton feed;
	JoystickButton climbOverride;
	JoystickButton dump1;
	JoystickButton deploy;

	JoystickButton driveDebug;
	JoystickButton shooterDebug;
	JoystickButton climberDebug;
	
	JoystickButton dump2;
};
#endif
