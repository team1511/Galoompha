#include "WaittoShoot.h"
#include "../Calc.h"

WaittoShoot::WaittoShoot() {
	Requires(Robot::shooterWheel);
}
// Called just before this Command runs the first time
void WaittoShoot::Initialize() {
	
}
// Called repeatedly when this Command is scheduled to run
void WaittoShoot::Execute() {
	Robot::shooterWheel->setTargetSpeed(Robot::oi->getSpeedSliderValue());
}
// Make this return true when this Command no longer needs to run execute()
bool WaittoShoot::IsFinished() {
	return Robot::shooterWheel->atTargetSpeed() && Robot::shooter->holdsDisk();
}
// Called once after isFinished returns true
void WaittoShoot::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaittoShoot::Interrupted() {
}
