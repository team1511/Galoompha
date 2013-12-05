#ifndef ACTIONS_CLIMB_H_
#define ACTIONS_CLIMB_H_

#include "Commands/CommandGroup.h"
#include "../utils/command_stub.h"

class DeploySequence: public CommandGroup {
public:
	DeploySequence();
};

class ArmsManual: public CommandStub {
public:
	ArmsManual();
	virtual void Execute();
	virtual void End();
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

class LockShooterBlob: public CommandStub {
public:
	LockShooterBlob();
	virtual void Execute();
};

// Auxiliary

class DoIfDeployed: public OneShotCommand {
public:
	DoIfDeployed(Command* c);
	virtual void Initialize();
private:
	Command* tostart;
};

#endif
