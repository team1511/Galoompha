#include "Robot.h"
Indexer* Robot::indexer = 0;
ShooterOther* Robot::shooter = 0;
ShooterWheel* Robot::shooterWheel = 0;
AnglingTool* Robot::anglingTool = 0;
Drive* Robot::drive = 0;
OI* Robot::oi = 0;
void Robot::RobotInit() {
	RobotMap::init();
	indexer = new Indexer();
	shooter = new ShooterOther();
	anglingTool = new AnglingTool();
	shooterWheel = new ShooterWheel();
	drive = new Drive();
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();
	autonomousCommand = new Autonomous();
}

void Robot::AutonomousInit() {
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// this line or comment it out.
	autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	if (autonomousCommand != NULL)
		Scheduler::GetInstance()->Run();
}
void Robot::TestPeriodic() {
	lw->Run();
}
START_ROBOT_CLASS(Robot);
