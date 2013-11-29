#ifndef ACTIONS_CLIMB_H_
#define ACTIONS_CLIMB_H_

#include "Commands/CommandGroup.h"
#include "utils/command_stub.h"

class DeploySequence: public CommandGroup {
public:
	DeploySequence();
};

class ArmsManual: public CommandStub {
public:
	ArmsManual();
	virtual void Execute();
};

// actions

class Dump: public OneShotCommand {
public:
	Dump();
	virtual void Execute();
};

class Deploy: public OneShotCommand {
public:
	Deploy();
	virtual void Execute();
};

// permanent locks

class LockShooter: public CommandStub {
public:
	LockShooter();
	virtual void Execute();
};

class LockLift: public CommandStub {
public:
	LockLift();
	virtual void Execute();
};

class LockIndexer: public CommandStub {
public:
	LockIndexer();
	virtual void Execute();
};

#endif
