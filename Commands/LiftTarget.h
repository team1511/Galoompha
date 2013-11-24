#ifndef LIFTTARGET_H
#define LIFTTARGET_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class LiftTarget: public PIDCommand {
public:
	LiftTarget(float angle);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double output);
};

#endif
