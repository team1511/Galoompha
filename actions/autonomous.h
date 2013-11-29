#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "Commands/CommandGroup.h"
#include "utils/command_stub.h"

class Generic3ShotAuton: public CommandGroup {
public:
	Generic3ShotAuton(const char* name, double angle, double power);
};

class AutonSwitcher: public OneShotCommand {
private:
	Generic3ShotAuton b2h;
	Generic3ShotAuton b2m;
	Generic3ShotAuton fc2h;
public:
	AutonSwitcher();
	virtual void Initialize();
};


#endif
