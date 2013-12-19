#ifndef ACTIONS_CMRATILT_H_
#define ACTIONS_CMRATILT_H_

#include "../utils/command_stub.h"

class CameraShootMode : public CommandStub {
public:
	CameraShootMode();
	virtual void Initialize();
	virtual void Execute();
private:
	double angle;
};

class CameraClimbMode : public CommandStub {
public:
	CameraClimbMode();
	virtual void Initialize();
	virtual void Execute();
private:
	double angle;
};

#endif //ACTIONS_CMRATILT_H_
