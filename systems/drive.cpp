#include "systems/drive.h"
#include "actions/drive_tank.h"
#include "robotmap.h"

Drive::Drive() :
		Subsystem("Drive") {
	leftMotor = RobotMap::driveLeftMotor;
	rightMotor = RobotMap::driveRightMotor;
	leftEncoder = RobotMap::driveLeftEncoder;
	rightEncoder = RobotMap::driveRightEncoder;
	power_left = 0.0;
	power_right = 0.0;
}

void Drive::InitDefaultCommand() {
	SetDefaultCommand(new TankDrive(kBrake));
}

void Drive::SetCoast(Drive::NeutralMode coast) {
	CANJaguar::NeutralMode flag;
	if (coast == kCoast) {
		flag = CANJaguar::kNeutralMode_Coast;
	} else {
		flag = CANJaguar::kNeutralMode_Brake;
	}
	leftMotor->ConfigNeutralMode(flag);
	rightMotor->ConfigNeutralMode(flag);
}

void Drive::Set(double left, double right) {
	power_left = left;
	power_right = right;
	leftMotor->Set(left);
	rightMotor->Set(-right);
}

double Drive::getLeftCurrent() {
	return leftMotor->GetOutputCurrent();
}
double Drive::getLeftSpeed() {
	return leftEncoder->getSpeed();
}
double Drive::getLeftPower() {
	return power_left;
}
double Drive::getRightCurrent() {
	return rightMotor->GetOutputCurrent();
}
double Drive::getRightSpeed() {
	return rightEncoder->getSpeed();
}
double Drive::getRightPower() {
	return power_right;
}
