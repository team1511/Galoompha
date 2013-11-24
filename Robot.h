#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

#include "Commands/Autonomous.h"
#include "Subsystems/AnglingTool.h"
#include "Subsystems/Indexer.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Drive.h"

#include "OI.h"

class Robot: public SimpleRobot {
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
