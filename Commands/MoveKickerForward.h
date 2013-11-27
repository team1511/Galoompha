#ifndef MOVE_KICKER_FORWARD_H
#define MOVE_KICKER_FORWARD_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class MoveKickerForward: public Command {
public:
	MoveKickerForward();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
