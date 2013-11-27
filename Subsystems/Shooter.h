#ifndef SHOOTER_H
#define SHOOTER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Utils/MonoEncoder.h"
#include "../Utils/ThreadlessPID.h"

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
