#include "Shooter.h"
#include "../Robotmap.h"
#include "../Commands/ShooterIdle.h"
#include "../Calc.h"

ShooterWheel::ShooterWheel() :
		Subsystem("Shooter Wheel"), pid(8.0, 0.0, 0.0, 0.7) {
	shooterWheel = RobotMap::shooterShooterWheel;
	shooterWheel->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
	shooterWheel->SetSafetyEnabled(false);

	encoder = RobotMap::shooterEncoder;

	target = 0.0;
}

ShooterOther::ShooterOther() :
		Subsystem("Shooter Other") {
	loadSensor = RobotMap::shooterLoadSensor;
	kicker = RobotMap::shooterKicker;
	blocker = RobotMap::shooterBlocker;
}

void ShooterWheel::InitDefaultCommand() {
	SetDefaultCommand(new ShooterIdle());
}

void ShooterOther::InitDefaultCommand() {

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
	target = speed;
	double actual = encoder->getSpeed();

	double output = pid.calc(target, actual);

	shooterWheel->Set(-bound(output, 0.0, 1.0));

	printf("goal %f real %f err %f | out %f\n", target, actual, target - actual, output);
}

#define CLOSE 0.05

bool ShooterWheel::atTargetSpeed() {
	double actual = encoder->getSpeed();
	double error = target - actual;
	return (error > -CLOSE && error < CLOSE);
}
