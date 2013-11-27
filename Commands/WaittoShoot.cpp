#include "WaittoShoot.h"
#include "../Calc.h"

WaittoShoot::WaittoShoot() {
	Requires(Robot::shooterWheel);
}
void WaittoShoot::Initialize() {
	
}
void WaittoShoot::Execute() {
	Robot::shooterWheel->setTargetSpeed(Robot::oi->getSpeedSliderValue());
}
bool WaittoShoot::IsFinished() {
	return Robot::shooterWheel->atTargetSpeed() && Robot::shooter->holdsDisk();
}
void WaittoShoot::End() {
	
}
void WaittoShoot::Interrupted() {
}
