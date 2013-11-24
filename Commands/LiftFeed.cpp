#include "LiftFeed.h"
#define ANGLE_FEED 0.44f
LiftFeed::LiftFeed() :
	PIDCommand("Lift Feed", ANGLE_PID_P, ANGLE_PID_I, ANGLE_PID_D, ANGLE_PID_PERIOD)
{
	Requires(Robot::anglingTool);
	GetPIDController()->SetSetpoint(ANGLE_FEED);
	GetPIDController()->Disable();
}
// Called just before this Command runs the first time
void LiftFeed::Initialize() {
	GetPIDController()->Reset();
	GetPIDController()->Enable();
}
// Called repeatedly when this Command is scheduled to run
void LiftFeed::Execute() {
}
// Make this return true when this Command no longer needs to run execute()
bool LiftFeed::IsFinished() {
	return Robot::getInstance().IsDisabled();
}
// Called once after isFinished returns true
void LiftFeed::End() {
	GetPIDController()->Disable();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftFeed::Interrupted() {
	GetPIDController()->Disable();
}
double LiftFeed::ReturnPIDInput() {
	return Robot::anglingTool->getAngle();
}
void LiftFeed::UsePIDOutput(double output) {
	// is it bad for the motor if we write 0.005 AND IT does nothing?
	Robot::anglingTool->setSpeed(output);
}
