#include "systems/climber.h"
#include "actions/climb.h"
#include "robotmap.h"

#define DEPLOY_OUT 0.1
#define DEPLOY_LOCK 0.7
#define DUMP_OUT 0.75
#define DUMP_LOCK 0.34

// Arms

Arms::Arms() :
		Subsystem("Arms") {
	motor = RobotMap::climberMotor;
	top = RobotMap::climberTopLimit;
	bottom = RobotMap::climberBottomLimit;
	hit_top = false;
	hit_bottom = false;
	was_broken = false;
	target = 0.0;
	output = 0.0;
}
double Arms::toSafePower(double goal) {
	bool at_top = hitTopLimit();

	if ((at_top || hit_top) && goal > 0) {
		hit_top = true;
		return 0.0;
	} else {
		hit_top = at_top;
	}

	bool at_bottom = hitBottomLimit();
	if ((at_bottom || hit_bottom) && goal < 0) {
		hit_bottom = true;
		return 0.0;
	} else {
		hit_bottom = at_bottom;
	}

	return goal;
}
void Arms::setPower(double power) {
	target = power;
	bool now_broken = Robot::oi->getClimberLimitsBroken();

	// reset state variables if reentering safe mode
	if (!was_broken && now_broken) {
		hit_top = false;
		hit_bottom = false;
	}
	was_broken = now_broken;

	// deliver power
	if (now_broken) {
		motor->Set(target * 0.3);
	} else {
		output = toSafePower(target);
		motor->Set(output);
	}
}
bool Arms::hitTopLimit() {
	return !top->Get();
}
bool Arms::hitBottomLimit() {
	return !bottom->Get();
}
double Arms::getGoal() {
	return target;
}
double Arms::getCurrent() {
	return motor->GetOutputCurrent();
}
double Arms::getOutput() {
	return output;
}

// Dumper

Dumper::Dumper() :
		ResettableSubsystem("Dumper") {
	servo = RobotMap::dumperServo;
	servo->Set(DUMP_LOCK);
}
void Dumper::Reset() {
	servo->Set(DUMP_LOCK);
}
void Dumper::dump(bool dump) {
	servo->Set(dump ? DUMP_OUT : DUMP_LOCK);
}
double Dumper::getPos() {
	return servo->Get();
}

// Deployer

Deployer::Deployer() :
		ResettableSubsystem("Deployer") {
	servo = RobotMap::deployerServo;
	servo->Set(DEPLOY_LOCK);
	deployed = false;
}

void Deployer::Reset() {
	servo->Set(DEPLOY_LOCK);
	deployed = false;
}
void Deployer::deploy(bool deploy) {
	servo->Set(deploy ? DEPLOY_OUT : DEPLOY_LOCK);
	deployed = true;
}
double Deployer::getPos() {
	return servo->Get();
}
bool Deployer::hasDeployed() {
	return deployed;
}

