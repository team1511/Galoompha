// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.

#include "LiftTarget.h"

LiftTarget::LiftTarget(float angle) :
		PIDCommand("Lift Target", ANGLE_PID_P, ANGLE_PID_I, ANGLE_PID_D,
				ANGLE_PID_PERIOD) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::anglingTool);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	GetPIDController()->SetSetpoint(angle);
	GetPIDController()->Disable();
}
void LiftTarget::Initialize() {
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