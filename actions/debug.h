#ifndef ACTIONS_DEBUG_H_
#define ACTIONS_DEBUG_H_

#include "utils/command_stub.h"

class DebugNothing : public CommandStub {
public:
	DebugNothing();
	virtual void Initialize();
};

class DebugShooter : public CommandStub {
public:
	DebugShooter();
	virtual void Execute();
};

class DebugDrive : public CommandStub {
public:
	DebugDrive();
	virtual void Execute();
};

class DebugClimber : public CommandStub {
public:
	DebugClimber();
	virtual void Execute();
};



#endif // ACTIONS_DEBUG_H_
