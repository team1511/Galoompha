// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "LiftStatic.h"
LiftStatic::LiftStatic() :
		PIDCommand("Lift Static", ANGLE_PID_P, ANGLE_PID_I, ANGLE_PID_D,
				ANGLE_PID_PERIOD) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::anglingTool);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	GetPIDController()->Disable();
}
// Called just before this Command runs the first time
void LiftStatic::Initialize() {
	GetPIDController()->Enable();
}
// Called repeatedly when this Command is scheduled to run
void LiftStatic::Execute() {
	float slider = -1 * Robot::oi->getVirtualStick()->GetY();

	GetPIDController()->SetSetpoint(slider);

	// hackn! to turn pid calculations off while disabled
	if (!GetPIDController()->IsEnabled()) {
		GetPIDController()->Enable();
	}
}
// Make this return true when this Command no longer needs to run execute()
bool LiftStatic::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void LiftStatic::End() {
	GetPIDController()->Disable();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftStatic::Interrupted() {
	GetPIDController()->Disable();
}

// this function MAY NEVER call PIDController::GetError()
double LiftStatic::ReturnPIDInput() {
	double v = Robot::anglingTool->getAngle(); 
	
	// if this code were in UsePIDOutput, the call
	// to Disable would call UsePIDOutput. to infinite loop.
	if (Robot::getInstance().IsDisabled()) {
		printf("Disabling\n");
		GetPIDController()->Reset();
	}
	return v;
}
void LiftStatic::UsePIDOutput(double output) {
	printf("o: %f\n",output);
	// is it bad for the motor if we write 0.005 AND IT does nothing?
	Robot::anglingTool->setSpeed(output);
}
