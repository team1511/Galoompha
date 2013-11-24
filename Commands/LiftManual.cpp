#include "LiftManual.h"
LiftManual::LiftManual() {
	Requires(Robot::anglingTool);
}
// Called just before this Command runs the first time
void LiftManual::Initialize() {
}
// Called repeatedly when this Command is scheduled to run
void LiftManual::Execute() {
	float slider = Robot::oi->getAngleSliderValue();
	
	if (slider < 0.2f && slider > -0.2f) {
		Robot::anglingTool->setSpeed(0.0);
	} else {
		Robot::anglingTool->setSpeed(slider * 0.5);
	}
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
