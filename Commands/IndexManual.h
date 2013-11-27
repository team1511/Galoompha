#ifndef INDEX_MANUAL_H
#define INDEX_MANUAL_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class IndexManual: public Command {
public:
	IndexManual();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
