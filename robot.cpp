#include "robot.h"
#include "actions/autonomous.h"

Indexer* Robot::indexer = 0;
ShooterOther* Robot::shooter = 0;
ShooterWheel* Robot::shooterWheel = 0;
AnglingTool* Robot::anglingTool = 0;
Drive* Robot::drive = 0;
OI* Robot::oi = 0;
Debug* Robot::debug = 0;

const double kRobotPeriod = 0.05;

void EnterMode(const char* name) {
	printf("\n       %s\n\n", name);
}

void Robot::RobotInit() {
	RobotMap::init();

	indexer = new Indexer();
	shooter = new ShooterOther();
	anglingTool = new AnglingTool();
	shooterWheel = new ShooterWheel();
	drive = new Drive();
	debug = new Debug();

	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();

	lw = LiveWindow::GetInstance();

	autonomousCommand = new AutonRoutine();
}

//The Pseudocode for each section is:
//
// 	 Initialize();
// 	 while (IsInProperState()) {
//     	 DoStuffPeriodically();
//     	 Wait();
// 	 }
// 	 Finalize();
//
//The two modes using the Scheduler finalize by
//removing (interrupting) all commands, leading to
//a call of Interrupted(), in which threaded resources
//like PIDControllers can be disabled.
//The next time the Scheduler runs, the Initialize()
//method for each command is called, and the state of
//the command can be reset, preventing state persistence
//that could lead to erratic behavior.

void Robot::Disabled() {
	EnterMode("Disabled");

	while (IsDisabled()) {
		// only commands that have RunWhenDisabled set true will do anything.
		// the default is false; no action.
		Scheduler::GetInstance()->Run();
		Wait(kRobotPeriod);
	}

	Scheduler::GetInstance()->RemoveAll();
}

void Robot::Autonomous() {
	EnterMode("Autonomous");
	if (autonomousCommand != NULL) {
		autonomousCommand->Start();
	}

	while (IsAutonomous() && IsEnabled()) {
		Scheduler::GetInstance()->Run();
		Wait(kRobotPeriod);
	}

	Scheduler::GetInstance()->RemoveAll();
}

void Robot::OperatorControl() {
	EnterMode("Teleoperated");

	while (IsOperatorControl() && IsEnabled()) {
		Scheduler::GetInstance()->Run();
		Wait(kRobotPeriod);
	}

	Scheduler::GetInstance()->RemoveAll();
}

void Robot::Test() {
	EnterMode("Test");

	while (IsTest() && IsEnabled()) {
		lw->Run();
		Wait(kRobotPeriod);
	}
}

START_ROBOT_CLASS(Robot);
