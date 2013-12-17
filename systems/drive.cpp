#include "../systems/drive.h"
#include "../actions/drive_tank.h"
#include "../robotmap.h"
#include "../robot.h"

Drive::Drive() :
	ResettableSubsystem("Drive") {
	leftMotor = RobotMap::driveLeftMotor;
	rightMotor = RobotMap::driveRightMotor;
	leftEncoder = RobotMap::driveLeftEncoder;
	rightEncoder = RobotMap::driveRightEncoder;
	power_left = 0.0;
	power_right = 0.0;
	voltage_mode = true;
}

void Drive::InitDefaultCommand() {
	SetDefaultCommand(new TankDrive(kBrake));
}

void Drive::Reset() {
	bool b = Robot::oi->getDriveOnVoltage();
	if (b && !voltage_mode) {
		SetVoltageMode(true);
	}
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

void Drive::SetVoltageMode(bool on) {
	CANJaguar::ControlMode m;
	voltage_mode = on;
	if (voltage_mode) {
		m = CANJaguar::kPercentVbus;
	} else {
		m = CANJaguar::kVoltage;
	}
	leftMotor->ChangeControlMode(m);
	leftMotor->EnableControl();

	rightMotor->ChangeControlMode(m);
	rightMotor->EnableControl();
}

void Drive::Set(double left, double right) {
	power_left = left;
	power_right = right;
	if (voltage_mode) {
		leftMotor->Set(13.0 * left);
		rightMotor->Set(13.0 * -right);
	} else {
		leftMotor->Set(left);
		rightMotor->Set(-right);
	}
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
