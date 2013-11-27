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
private:
	Joystick* virtualStick;
	JoystickButton* indexBroken;
	JoystickButton* angleBroken;
	JoystickButton* coastMode;

	Joystick* auxStick;
	JoystickButton* shootButton;
	JoystickButton* feedButton;

	Joystick* rightDrive;

	Joystick* leftDrive;
	JoystickButton* driveDebug;
	JoystickButton* shooterDebug;
	JoystickButton* climberDebug;
};
#endif
