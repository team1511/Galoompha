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
class Robot: public IterativeRobot {
public:
	Command *autonomousCommand;
	static OI *oi;
	LiveWindow *lw;

	static Indexer* indexer;
	static ShooterOther* shooter;
	static AnglingTool* anglingTool;
	static ShooterWheel* shooterWheel;
	static Drive* drive;

	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif
