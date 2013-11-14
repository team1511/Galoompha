// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "LiftManual.h"
LiftManual::LiftManual() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::anglingTool);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void LiftManual::Initialize() {
}
// Called repeatedly when this Command is scheduled to run
void LiftManual::Execute() {
	float slider = -1 * Robot::oi->getVirtualStick()->GetY();
	
	float post = slider;
	if (post < 0.2f && post > -0.2f) {
		post = 0;
	}
	
	Robot::anglingTool->setSpeed(slider * 0.5);
}
// Make this return true when this Command no longer needs to run execute()
bool LiftManual::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void LiftManual::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftManual::Interrupted() {
}
