#ifndef OI_H
#define OI_H
#include "WPILib.h"

class OI {
public:
	OI();

	double getLeftDrivePower();
	double getRightDrivePower();
	double getSpeedSliderValue();
	double getAngleSliderValue();
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
};
#endif
