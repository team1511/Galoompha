#ifndef RAISE_BLOCKER_H
#define RAISE_BLOCKER_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class RaiseBlocker: public Command {
public:
	RaiseBlocker();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
