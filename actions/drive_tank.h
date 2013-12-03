#ifndef TANK_DRIVE_H
#define TANK_DRIVE_H

#include "../systems/drive.h"
#include "../utils/command_stub.h"

class TankDrive: public CommandStub {
public:
	TankDrive(Drive::NeutralMode coast);
	virtual void Initialize();
	virtual void Execute();
private:
	Drive::NeutralMode coasting;
};

#endif
