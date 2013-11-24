#ifndef LIFT_MANUAL_H
#define LIFT_MANUAL_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class LiftManual: public Command {
public:
	LiftManual();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
