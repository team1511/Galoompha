#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "LiveWindow/LiveWindow.h"

#include "utils/sendable_command_chooser.h"

#include "robotmap.h"
#include "controls.h"

#include "systems/drive.h"
#include "systems/indexer.h"
#include "systems/shooter.h"
#include "systems/lift.h"
#include "systems/debug.h"
#include "systems/climber.h"

class Robot: public SimpleRobot {
public:
	static OI* oi;
	// subsystems
	static Indexer* indexer;
	static ShooterOther* shooter;
	static AnglingTool* anglingTool;
	static ShooterWheel* shooterWheel;
	static Drive* drive;
	static Debug* debug;
	static Arms* arms;
	static Dumper* dumper;
	static Deployer* deployer;
	// methods
	virtual void RobotInit();
	virtual void Disabled();
	virtual void Autonomous();
    virtual void OperatorControl();
    virtual void Test();

private:
    SendableCommandChooser* autonSelector;
	LiveWindow* lw;
};

#endif
