#include "systems/drive.h"
#include "actions/drive_tank.h"
#include "robotmap.h"

Drive::Drive() :
		Subsystem("Drive") {
	leftMotor = RobotMap::driveLeftMotor;
	rightMotor = RobotMap::driveRightMotor;
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

void Drive::SetSpeeds(float left, float right) {
	leftMotor->Set(left);
	rightMotor->Set(-right);
}

