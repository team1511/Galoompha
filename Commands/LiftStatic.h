#ifndef LIFT_STATIC_H
#define LIFT_STATIC_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class LiftStatic: public PIDCommand {
public:
	LiftStatic();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double output);
};

#endif
