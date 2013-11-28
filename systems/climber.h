#ifndef SYSTEMS_CLIMBER_H_
#define SYSTEMS_CLIMBER_H_

#include "WPILib.h"

class Arms: public Subsystem {
public:
	Arms();
	void InitDefaultCommand();

	void setPower(double power);
	bool hitTopLimit();
	bool hitBottomLimit();
	double getGoal();
	double getCurrent();
	double getOutput();
private:
	double toSafePower(double goal);
	CANJaguar* motor;
	DigitalInput* top;
	DigitalInput* bottom;
	bool hit_top;
	bool hit_bottom;
	bool was_broken;
	double target;
	double output;
};

class Dumper: public Subsystem {
public:
	Dumper();
	void InitDefaultCommand();

	void dump(bool dump);
	void lock(bool lock);
	bool isLocked();

	double getPos();
private:
	bool locked;
	Servo* servo;
};

class Deployer: public Subsystem {
public:
	Deployer();
	void InitDefaultCommand();

	void deploy(bool deploy);
	double getPos();
private:
	Servo* servo;
};

#endif // SYSTEMS_CLIMBER_H_
