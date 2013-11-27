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

	void setTargetSpeed(double speed);
	bool atTargetSpeed();

	double getSpeed();
	double getTarget();
	double getCurrent();
};

class ShooterOther: public Subsystem {
public:
	ShooterOther();
	void InitDefaultCommand();
	
	void block(bool doit);
	void kick(bool forward);

	bool holdsDisk();
	bool isBlockerUp();
	bool isKickerOut();
private:
	DigitalInput* loadSensor;
	Servo* kicker;
	Servo* blocker;
	bool kicked;
	bool blocked;
};
#endif
