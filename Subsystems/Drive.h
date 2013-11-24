#ifndef DRIVE_H_
#define DRIVE_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drive: public Subsystem {
private:
	CANJaguar* leftMotor;
	CANJaguar* rightMotor;
public:
	typedef enum {
		kCoast, kBrake
	} NeutralMode;

	Drive();
	void InitDefaultCommand();

	void SetCoast(NeutralMode coast);
	void SetSpeeds(float left, float right);
};

#endif /* DRIVE_H_ */
