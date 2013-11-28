#ifndef ACTIONS_CLIMB_H_
#define ACTIONS_CLIMB_H_

#include "Commands/CommandGroup.h"
#include "utils/command_stub.h"

class DeploySequence: public CommandGroup {
public:
	DeploySequence();
};

class ArmsRest: public CommandStub {
public:
	ArmsRest();
};

class ArmsManual: public CommandStub {
public:
	ArmsManual();
	virtual void Execute();
};

class DumperRest: public CommandStub {
public:
	DumperRest();
};

class DeployerRest: public CommandStub {
public:
	DeployerRest();
};

// actions

class Dump: public OneShotCommand {
public:
	Dump();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
};

class Deploy: public OneShotCommand {
public:
	Deploy();
	virtual void Execute();
	virtual void End();
};

// stately locks

class UnlockDumper: public OneShotCommand {
public:
	UnlockDumper();
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
