#ifndef UTILS_COMMAND_STUB_H
#define UTILS_COMMAND_STUB_H

#include "Commands/Command.h"

class CommandStub: public Command {
public:
	explicit CommandStub(const char* name);
	explicit CommandStub(const char* name, double timeout);
protected:
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

class OneShotCommand : public CommandStub {
public:
	OneShotCommand(const char* f);
	virtual bool IsFinished();
};

#endif
