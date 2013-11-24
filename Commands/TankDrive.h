#ifndef TANK_DRIVE_H
#define TANK_DRIVE_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class TankDrive: public Command {
public:
	TankDrive(Drive::NeutralMode coast);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	Drive::NeutralMode coasting;
};

#endif
