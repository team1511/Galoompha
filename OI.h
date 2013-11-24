#ifndef OI_H
#define OI_H
#include "WPILib.h"
class OI {
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
public:
	OI();

	Joystick* getLeftDrive();
	Joystick* getRightDrive();
	Joystick* getAuxStick();
	Joystick* getVirtualStick();
};
#endif
