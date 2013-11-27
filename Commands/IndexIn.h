#ifndef INDEX_IN_H
#define INDEX_IN_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class IndexIn: public Command {
public:
	IndexIn();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
