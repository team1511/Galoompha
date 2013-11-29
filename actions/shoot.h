#ifndef SHOOT_DISK_H
#define SHOOT_DISK_H

#include "Commands/CommandGroup.h"
#include "utils/command_stub.h"

class ShootDisk: public CommandGroup {
public:
	ShootDisk();
};

class MoveKicker: public OneShotCommand {
public:
	typedef enum {kKick, kRetract} Direction;
	MoveKicker(Direction d);
	virtual void Execute();
private:
	Direction dir;
};

class MoveBlocker: public OneShotCommand {
public:
	typedef enum {kBlock, kClear} Position;
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
public:
	MaintainSpeed();
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
