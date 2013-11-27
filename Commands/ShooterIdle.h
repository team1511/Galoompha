#ifndef SHOOTER_IDLE_H
#define SHOOTER_IDLE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class ShooterIdle: public Command {
public:
	ShooterIdle();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
