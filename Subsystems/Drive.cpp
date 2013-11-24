#include "Drive.h"
#include "../Commands/TankDrive.h"

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

// deal with current limiting in this, reset on teleop init?
// create a global reset/initialize call to all Subsystems(/Commands?) ?
// well, most commands should best be stateless, but initialize should
// be called on all of them at teleop
void Drive::SetSpeeds(float left, float right) {
	leftMotor->Set(left);
	rightMotor->Set(-right);
}

