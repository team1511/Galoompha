#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "Commands/CommandGroup.h"
#include "utils/command_stub.h"

class Generic3ShotAuton: public CommandGroup {
public:
	Generic3ShotAuton(const char* name, double angle, double power);
};

class AutonBackToHigh : public Generic3ShotAuton {
public:
	AutonBackToHigh();
};
class AutonBackToMid : public Generic3ShotAuton {
public:
	AutonBackToMid();
};
class AutonFrontCenterToHigh : public Generic3ShotAuton {
public:
	AutonFrontCenterToHigh();
};

class AutonNull : OneShotCommand {
public:
	AutonNull();
};


#endif
