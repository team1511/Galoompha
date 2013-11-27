#ifndef INDEX_FULL_H
#define INDEX_FULL_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class IndexFull: public Command {
public:
	IndexFull();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
