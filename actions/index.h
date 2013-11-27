#ifndef INDEX_MANUAL_H
#define INDEX_MANUAL_H

#include "utils/command_stub.h"
#include "Commands/CommandGroup.h"

class IndexManual: public CommandStub {
public:
	IndexManual();
	virtual void Execute();
};

class IndexCycle: public CommandGroup {
public:
	IndexCycle();
};

class IndexIn: public CommandStub {
public:
	IndexIn();
	virtual void Execute();
	virtual bool IsFinished();
};

class IndexFull: public CommandStub {
public:
	IndexFull();
	virtual void Execute();
	virtual bool IsFinished();
};

#endif
