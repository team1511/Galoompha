#ifndef SHOOT_DISK_H
#define SHOOT_DISK_H

#include "Commands/CommandGroup.h"
#include "utils/command_stub.h"
#include "systems/shooter.h"

class ShootDisk: public CommandGroup {
public:
	ShootDisk(ShooterWheel::SpeedSource v = ShooterWheel::kControls,
			double speed = 0.0);
};

class MoveKicker: public OneShotCommand {
public:
	typedef enum {
		kKick, kRetract
	} Direction;
	MoveKicker(Direction d);
	virtual void Execute();
private:
	Direction dir;
};

class MoveBlocker: public OneShotCommand {
public:
	typedef enum {
		kBlock, kClear
	} Position;
	MoveBlocker(Position forward);
	virtual void Execute();
private:
	Position pos;
};

// Wheel

class ShooterIdle: public CommandStub {
public:
	ShooterIdle();
	virtual void Execute();
};

class MaintainSpeed: public CommandStub {
private:
	ShooterWheel::SpeedSource mode;
	double target;
public:
	MaintainSpeed(ShooterWheel::SpeedSource v = ShooterWheel::kControls,
			double speed = 0.0);
	virtual void Execute();
};

class WaittoShoot: public CommandGroup {
public:
	WaittoShoot();
};

class WaitUntilReadyToShoot: public CommandStub {
public:
	WaitUntilReadyToShoot();
	virtual bool IsFinished();
};

#endif
