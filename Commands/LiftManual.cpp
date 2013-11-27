#include "LiftManual.h"
LiftManual::LiftManual() {
	Requires(Robot::anglingTool);
}
void LiftManual::Initialize() {
}
void LiftManual::Execute() {
	float slider = Robot::oi->getAngleSliderValue();
	
	if (slider < 0.2f && slider > -0.2f) {
		Robot::anglingTool->setSpeed(0.0);
	} else {
		Robot::anglingTool->setSpeed(slider * 0.5);
	}
}
bool LiftManual::IsFinished() {
	return false;
}
void LiftManual::End() {
	
}
void LiftManual::Interrupted() {
}
