#ifndef UTILS_PID_COMMAND_STUB_H
#define UTILS_PID_COMMAND_STUB_H

#include "Commands/PIDCommand.h"

class PIDCommandStub: public PIDCommand {
public:
	explicit PIDCommandStub(const char* name, double p, double i, double d,
			double period);
protected:
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
