#include "systems/shooter.h"
#include "robotmap.h"
#include "actions/shoot.h"
#include "utils/calc.h"

#define SPEED_CLOSE 0.05

#define BLOCK_HIGH 0.5
#define BLOCK_LOW 1.0

#define KICK_OUT 0.7
#define KICK_BACK 0.48

// Shooter Wheel

ShooterWheel::ShooterWheel() :
		Subsystem("Shooter Wheel"), pid(8.0, 0.0, 0.0, 0.7) {
	shooterWheel = RobotMap::shooterShooterWheel;
	shooterWheel->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
	shooterWheel->SetSafetyEnabled(false);

	encoder = RobotMap::shooterEncoder;

	target = 0.0;
}
void ShooterWheel::InitDefaultCommand() {
	SetDefaultCommand(new ShooterIdle());
}
void ShooterWheel::setTargetSpeed(double speed) {
	target = speed;
	double actual = encoder->getSpeed();
	double output = pid.calc(target, actual);
	shooterWheel->Set(-bound(output, 0.0, 1.0));

	printf("goal %f real %f err %f | out %f\n", target, actual, target - actual, output);
}
bool ShooterWheel::atTargetSpeed() {
	double actual = encoder->getSpeed();
	double error = target - actual;
	return (error > -SPEED_CLOSE && error < SPEED_CLOSE);
}

double ShooterWheel::getSpeed() {
	return encoder->getSpeed();
}
double ShooterWheel::getTarget() {
	return target;
}
double ShooterWheel::getCurrent() {
	return shooterWheel->GetOutputCurrent();
}

// Shooter Other

ShooterOther::ShooterOther() :
		Subsystem("Shooter Other") {
	loadSensor = RobotMap::shooterLoadSensor;
	kicker = RobotMap::shooterKicker;
	blocker = RobotMap::shooterBlocker;
	block(false);
	kick(false);

}
void ShooterOther::InitDefaultCommand() {
}


void ShooterOther::block(bool doit) {
	blocked = doit;
	blocker->Set(blocked ? BLOCK_HIGH : BLOCK_LOW);
}
void ShooterOther::kick(bool forward) {
	kicked = forward;
	kicker->Set(kicked ? KICK_OUT : KICK_BACK);
}

bool ShooterOther::holdsDisk() {
	return loadSensor->Get() == 0;
}
bool ShooterOther::isBlockerUp() {
	return blocked;
}
bool ShooterOther::isKickerOut() {
	return kicked;
}
