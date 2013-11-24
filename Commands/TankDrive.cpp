#include "TankDrive.h"

TankDrive::TankDrive(Drive::NeutralMode coast) {
	Requires(Robot::drive);
	coasting = coast;
}
// Called just before this Command runs the first time. CALLED AGAIN IF RESURRECTED, WPILIB guys!
void TankDrive::Initialize() {
	Robot::drive->SetCoast(coasting);
}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {
	double power_l = Robot::oi->getLeftDrivePower();
	double power_r = Robot::oi->getRightDrivePower();
	Robot::drive->SetSpeeds(power_l, power_r);
}
// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished() {
	return true;
}
// Called once after isFinished returns true
void TankDrive::End() {
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive::Interrupted() {
}
