#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "LiveWindow/LiveWindow.h"

#include "robotmap.h"
#include "controls.h"

#include "systems/drive.h"
#include "systems/indexer.h"
#include "systems/shooter.h"
#include "systems/lift.h"

class Robot: public SimpleRobot {
public:
	static OI* oi;
	// subsystems
	static Indexer* indexer;
	static ShooterOther* shooter;
	static AnglingTool* anglingTool;
	static ShooterWheel* shooterWheel;
	static Drive* drive;
	// methods
	virtual void RobotInit();
	virtual void Disabled();
	virtual void Autonomous();
    virtual void OperatorControl();
    virtual void Test();

private:
	Command* autonomousCommand;
	LiveWindow* lw;
};

#endif