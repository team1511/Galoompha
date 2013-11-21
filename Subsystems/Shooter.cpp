// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Shooter.h"
#include "../Robotmap.h"
#include "../Commands/ShooterIdle.h"
#include "../Calc.h"


ShooterWheel::ShooterWheel() : Subsystem("Shooter Wheel") {
	shooterWheel = RobotMap::shooterShooterWheel;
	shooterWheel->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
	shooterWheel->SetSafetyEnabled(false);
}



ShooterOther::ShooterOther() : Subsystem("Shooter Other") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	loadSensor = RobotMap::shooterLoadSensor;
	kicker = RobotMap::shooterKicker;
	blocker = RobotMap::shooterBlocker;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void ShooterWheel::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new ShooterIdle());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void ShooterOther::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
bool ShooterOther::holdsDisk() {
	return loadSensor->Get() == 0;
}
#define BLOCK_HIGH 0.5
#define BLOCK_LOW 1.0
void ShooterOther::block(bool doit) {
	blocker->Set(doit ? BLOCK_HIGH : BLOCK_LOW);
}
#define KICK_OUT 0.7
#define KICK_BACK 0.48
void ShooterOther::kick(bool forward) {
	kicker->Set(forward ? KICK_OUT : KICK_BACK);
}
void ShooterWheel::setTargetSpeed(float speed) {
	shooterWheel->Set(-speed);
}
bool ShooterWheel::atTargetSpeed() {
	return true;
}

void  ShooterWheel::runWheelFromOI() {
	float slider = Robot::oi->getVirtualStick()->GetX();
	float speed = linearRangeScale(slider, -1.0f, 1.0f, 0.3f, 1.0f);
	setTargetSpeed(speed);
}
