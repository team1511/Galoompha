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
		modeCoast, modeBrake
	} NeutralMode;

	Drive();
	void InitDefaultCommand();

	void SetCoast(bool coast);
	void SetSpeeds(float left, float right);
};

#endif /* DRIVE_H_ */
