#ifndef SHOOT_DISK_H
#define SHOOT_DISK_H

#include "Commands/CommandGroup.h"
#include "utils/command_stub.h"

class ShootDisk: public CommandGroup {
public:
	ShootDisk();
};

// Kicker

class MoveKickerForward: public CommandStub {
public:
	MoveKickerForward();
	virtual void Execute();
	virtual bool IsFinished();
};

class RetractKicker: public CommandStub {
public:
	RetractKicker();
	virtual void Execute();
	virtual bool IsFinished();
};

// Blocker

class RaiseBlocker: public CommandStub {
public:
	RaiseBlocker();
	virtual void Execute();
	virtual bool IsFinished();
};

class DropBlocker: public CommandStub {
public:
	DropBlocker();
	virtual void Execute();
	virtual bool IsFinished();
};

// Wheel

class ShooterIdle: public CommandStub {
public:
	ShooterIdle();
	virtual void Execute();
};

class WaittoShoot: public CommandStub {
public:
	WaittoShoot();
	virtual void Execute();
	virtual bool IsFinished();
};

class MaintainSpeed: public CommandStub {
public:
	MaintainSpeed();
	virtual void Execute();
};

#endif
