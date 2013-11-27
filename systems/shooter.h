#ifndef SHOOTER_H
#define SHOOTER_H

#include "WPILib.h"

#include "utils/mono_encoder.h"
#include "utils/threadless_pid.h"

class ShooterWheel: public Subsystem {
private:
	ThreadlessPID pid;

	CANJaguar* shooterWheel;
	MonoEncoder* encoder;
	
	double target;
public:
	ShooterWheel();
	void InitDefaultCommand();

	void setTargetSpeed(float speed);
	bool atTargetSpeed();
};

class ShooterOther: public Subsystem {
private:
	DigitalInput* loadSensor;
	Servo* kicker;
	Servo* blocker;
public:
	ShooterOther();
	void InitDefaultCommand();
	
	bool holdsDisk();
	void block(bool doit);
	void kick(bool forward);
	bool isLoaded();
};
#endif
