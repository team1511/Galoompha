#ifndef DROP_BLOCKER_H
#define DROP_BLOCKER_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 * Sets the servo to a position; ends
 */
class DropBlocker: public Command {
public:
	DropBlocker();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
};

#endif
