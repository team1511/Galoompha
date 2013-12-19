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
	voltage_mode = false;
	coast_mode = false;
}

void Drive::InitDefaultCommand() {
	SetDefaultCommand(new TankDrive(kBrake));
}

void Drive::Reset() {
	bool b = Robot::oi->getDriveOnVoltage();
	if (b != voltage_mode) {
		SetVoltageMode(b);
	}
	voltage_mode = b;
}

void Drive::SetCoast(Drive::NeutralMode coast) {
	CANJaguar::NeutralMode flag;
	if (coast == kCoast) {
		flag = CANJaguar::kNeutralMode_Coast;
		coast_mode = true;
	} else {
		flag = CANJaguar::kNeutralMode_Brake;
		coast_mode = false;
	}
	leftMotor->ConfigNeutralMode(flag);
	rightMotor->ConfigNeutralMode(flag);
}

void Drive::SetVoltageMode(bool on) {
	
	voltage_mode = on;
	CANJaguar::ControlMode m = voltage_mode ? CANJaguar::kVoltage : CANJaguar::kPercentVbus;
	leftMotor->ChangeControlMode(m);
	rightMotor->ChangeControlMode(m);

	rightMotor->EnableControl();
	leftMotor->EnableControl();
}

void Drive::Set(double left, double right) {
	power_left = left;
	power_right = right;
	if (voltage_mode) {
		leftMotor->Set(13.0 * left);
		rightMotor->Set(-13.0 * right);
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

bool Drive::isCoasting() {
	return coast_mode;
}
bool Drive::isVoltaging() {
	return voltage_mode;
}
