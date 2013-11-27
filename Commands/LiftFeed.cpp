#include "LiftFeed.h"
#define ANGLE_FEED 0.44f
LiftFeed::LiftFeed() :
	PIDCommand("Lift Feed", ANGLE_PID_P, ANGLE_PID_I, ANGLE_PID_D, ANGLE_PID_PERIOD)
{
	Requires(Robot::anglingTool);
	GetPIDController()->SetSetpoint(ANGLE_FEED);
	GetPIDController()->Disable();
}
void LiftFeed::Initialize() {
	GetPIDController()->Reset();
	GetPIDController()->Enable();
}
void LiftFeed::Execute() {
}
bool LiftFeed::IsFinished() {
	return Robot::getInstance().IsDisabled();
}
void LiftFeed::End() {
	GetPIDController()->Disable();
}
void LiftFeed::Interrupted() {
	GetPIDController()->Disable();
}
double LiftFeed::ReturnPIDInput() {
	return Robot::anglingTool->getAngle();
}
void LiftFeed::UsePIDOutput(double output) {
	// is it bad for the motor if we write 0.005 AND it does nothing?
	Robot::anglingTool->setSpeed(output);
}
