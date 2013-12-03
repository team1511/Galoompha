#ifndef DRIVE_H_
#define DRIVE_H_

#include "WPILib.h"
#include "../utils/mono_encoder.h"

class Drive: public Subsystem {
public:
	typedef enum {
		kCoast, kBrake
	} NeutralMode;

	Drive();
	void InitDefaultCommand();

	void SetCoast(NeutralMode coast);
	void Set(double left, double right);

	double getLeftCurrent();
	double getLeftSpeed();
	double getLeftPower();
	double getRightCurrent();
	double getRightSpeed();
	double getRightPower();
private:
	CANJaguar* leftMotor;
	CANJaguar* rightMotor;
	MonoEncoder* leftEncoder;
	MonoEncoder* rightEncoder;

	double power_left;
	double power_right;
};

#endif /* DRIVE_H_ */
