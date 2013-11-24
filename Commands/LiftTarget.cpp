#include "LiftTarget.h"

LiftTarget::LiftTarget(float angle) :
		PIDCommand("Lift Target", ANGLE_PID_P, ANGLE_PID_I, ANGLE_PID_D,
				ANGLE_PID_PERIOD) {
	Requires(Robot::anglingTool);
	GetPIDController()->SetSetpoint(angle);
	GetPIDController()->Disable();
}
void LiftTarget::Initialize() {
	GetPIDController()->Reset();
	GetPIDController()->Enable();
}
void LiftTarget::Execute() {
}
bool LiftTarget::IsFinished() {
	return false;
}
void LiftTarget::End() {
	GetPIDController()->Disable();
}
void LiftTarget::Interrupted() {
	GetPIDController()->Disable();
}
double LiftTarget::ReturnPIDInput() {
	return Robot::anglingTool->getAngle();
}
void LiftTarget::UsePIDOutput(double output) {
	Robot::anglingTool->setSpeed(output);
}
