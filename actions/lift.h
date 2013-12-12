#ifndef LIFT_MANUAL_H
#define LIFT_MANUAL_H

#include "../utils/command_stub.h"
#include "../utils/pid_command_stub.h"

class LiftManual: public CommandStub {
public:
	LiftManual();
	virtual void Execute();
};

class LiftStatic: public PIDCommandStub {
public:
	LiftStatic();
	virtual void Initialize();
	virtual void Execute();
	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double output);
};

class LiftTarget: public PIDCommandStub {
public:
	LiftTarget(double angle);
	LiftTarget(const char* name, double angle);
	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double output);
	bool OnTarget();
};

class LiftToTarget: public LiftTarget {
public:
	LiftToTarget(double angle);
	virtual bool IsFinished();
};

class LiftFeed: public LiftTarget {
public:
	LiftFeed();
	virtual void Initialize();
	virtual void Execute();
	virtual void End();
	virtual void Interrupted();
};

#endif
