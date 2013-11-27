#ifndef MAINTAINSPEED_H
#define MAINTAINSPEED_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class MaintainSpeed: public Command {
public:
	MaintainSpeed();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
