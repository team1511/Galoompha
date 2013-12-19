#ifndef DRIVE_H_
#define DRIVE_H_

#include "WPILib.h"
#include "../utils/mono_encoder.h"
#include "../utils/resettable_subsystem.h"

class Drive: public ResettableSubsystem {
public:
	typedef enum {
		kCoast, kBrake
	} NeutralMode;

	Drive();
	void InitDefaultCommand();
	virtual void Reset();

	void SetCoast(NeutralMode coast);
	void SetVoltageMode(bool on);
	void Set(double left, double right);

	double getLeftCurrent();
	double getLeftSpeed();
	double getLeftPower();
	double getRightCurrent();
	double getRightSpeed();
	double getRightPower();
	
	bool isCoasting();
	bool isVoltaging();
private:
	CANJaguar* leftMotor;
	CANJaguar* rightMotor;
	MonoEncoder* leftEncoder;
	MonoEncoder* rightEncoder;

	double power_left;
	double power_right;
	
	bool coast_mode;
	bool voltage_mode;
};

#endif /* DRIVE_H_ */
