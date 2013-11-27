#include "actions/drive_tank.h"
#include "robot.h"

const char* genName(Drive::NeutralMode coast) {
	switch (coast) {
	case Drive::kCoast:
		return "Tank Drive: Coast";
	case Drive::kBrake:
		return "Tank Drive: Brake";
	}
}

TankDrive::TankDrive(Drive::NeutralMode coast) :
		CommandStub(genName(coast)) {
	Requires(Robot::drive);
	coasting = coast;
}
void TankDrive::Initialize() {
	Robot::drive->SetCoast(coasting);
}
void TankDrive::Execute() {
	double left = Robot::oi->getLeftDrivePower();
	double right = Robot::oi->getRightDrivePower();
	Robot::drive->Set(left, right);
}
