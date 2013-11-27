#ifndef RETRACT_KICKER_H
#define RETRACT_KICKER_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class RetractKicker: public Command {
public:
	RetractKicker();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
