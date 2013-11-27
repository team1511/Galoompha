#ifndef WAIT_TO_SHOOT_H
#define WAIT_TO_SHOOT_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class WaittoShoot: public Command {
public:
	WaittoShoot();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
