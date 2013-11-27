#include "MaintainSpeed.h"
#include "../Calc.h"

MaintainSpeed::MaintainSpeed() {
	Requires(Robot::shooterWheel);
}
void MaintainSpeed::Initialize() {
	
}
void MaintainSpeed::Execute() {
	Robot::shooterWheel->setTargetSpeed(Robot::oi->getSpeedSliderValue());
}
bool MaintainSpeed::IsFinished() {
	return false;
}
void MaintainSpeed::End() {
	
}
void MaintainSpeed::Interrupted() {
}
