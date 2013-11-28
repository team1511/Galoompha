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
private:
	Joystick* virtualStick;
	JoystickButton* indexBroken;
	JoystickButton* angleBroken;
	JoystickButton* coastMode;

	Joystick* auxStick;
	JoystickButton* shoot;
	JoystickButton* feed;
	JoystickButton* climbOverride;
	JoystickButton* dump1;
	JoystickButton* dump2;
	JoystickButton* deploy;

	Joystick* rightDrive;

	Joystick* leftDrive;
	JoystickButton* driveDebug;
	JoystickButton* shooterDebug;
	JoystickButton* climberDebug;
};
#endif
