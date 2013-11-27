#include "actions/drive_tank.h"
#include "robot.h"

TankDrive::TankDrive(Drive::NeutralMode coast) :
		CommandStub("Tank Drive") {
	Requires(Robot::drive);
	coasting = coast;
}
void TankDrive::Initialize() {
	Robot::drive->SetCoast(coasting);
}
void TankDrive::Execute() {
	double power_l = Robot::oi->getLeftDrivePower();
	double power_r = Robot::oi->getRightDrivePower();
	Robot::drive->SetSpeeds(power_l, power_r);
}
