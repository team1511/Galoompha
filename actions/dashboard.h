#ifndef ACTIONS_DASHBOARD_H_
#define ACTIONS_DASHBOARD_H_

#include "../utils/command_stub.h"

class UpdateDashboard: public CommandStub {
public:
	UpdateDashboard();
	virtual void Execute();
};

#endif
