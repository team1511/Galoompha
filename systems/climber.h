#ifndef SYSTEMS_CLIMBER_H_
#define SYSTEMS_CLIMBER_H_

#include "WPILib.h"
#include "../utils/resettable_subsystem.h"

class Arms: public Subsystem {
public:
	Arms();
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

class Dumper: public ResettableSubsystem {
public:
	Dumper();
	virtual void Reset();

	void dump(bool dump);

	double getPos();
private:
	Servo* servo;
};

class Deployer: public ResettableSubsystem {
public:
	Deployer();
	virtual void Reset();

	void deploy(bool deploy);
	bool hasDeployed();
	double getPos();
private:
	Servo* servo;
	bool deployed;
};

#endif // SYSTEMS_CLIMBER_H_
