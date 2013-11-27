#ifndef LIFT_FEED_H
#define LIFT_FEED_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class LiftFeed: public PIDCommand {
public:
	LiftFeed();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double output);
};

#endif
