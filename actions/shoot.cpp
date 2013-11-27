#include "actions/shoot.h"
#include "utils/calc.h"
#include "robot.h"

// should these constants really be pulled out?
// this style is rather legible...
#define DROP_TIME 0.5
#define GUARD_LOWER_TIME 0.3
#define PUSHER_OUT_TIME 0.5
#define PUSHER_BACK_TIME 0.3
#define SPEED_TIMEOUT 3.0

ShootDisk::ShootDisk() :
		CommandGroup("Shoot Disk") {
	AddSequential(new PrintCommand("Waiting!"));
	AddSequential(new WaittoShoot(), SPEED_TIMEOUT);

	AddParallel(new MaintainSpeed());
	AddSequential(new PrintCommand("Go!!"));
	AddSequential(new WaitCommand(DROP_TIME));

	AddSequential(new DropBlocker());
	AddSequential(new WaitCommand(GUARD_LOWER_TIME));
	AddSequential(new MoveKickerForward());
	AddSequential(new WaitCommand(PUSHER_OUT_TIME));
	AddSequential(new RetractKicker());
	AddSequential(new WaitCommand(PUSHER_BACK_TIME));
	AddSequential(new RaiseBlocker());
	AddSequential(new PrintCommand("Done!!!"));
}

// Move Kicker Forward

MoveKickerForward::MoveKickerForward() :
		CommandStub("Move Kicker Forward") {
	Requires(Robot::shooter);
}
void MoveKickerForward::Execute() {
	Robot::shooter->kick(true);
}
bool MoveKickerForward::IsFinished() {
	return true;
}

// Retract Kicker

RetractKicker::RetractKicker() :
		CommandStub("Retract Kicker") {
	Requires(Robot::shooter);
}
void RetractKicker::Execute() {
	Robot::shooter->kick(false);
}
bool RetractKicker::IsFinished() {
	return true;
}

// Raise Blocker

RaiseBlocker::RaiseBlocker() :
		CommandStub("Raise Blocker") {
	Requires(Robot::shooter);
}
void RaiseBlocker::Execute() {
	Robot::shooter->block(true);
}
bool RaiseBlocker::IsFinished() {
	return true;
}

// Drop Blocker

DropBlocker::DropBlocker() {
	Requires(Robot::shooter);
}
void DropBlocker::Execute() {
	Robot::shooter->block(false);
}
bool DropBlocker::IsFinished() {
	return true;
}

// Shooter Idle

ShooterIdle::ShooterIdle() :
		CommandStub("Shooter Idle") {
	Requires(Robot::shooterWheel);
}
void ShooterIdle::Execute() {
	Robot::shooterWheel->setTargetSpeed(0.0);
}

// Wait To Shoot

WaittoShoot::WaittoShoot() :
		CommandStub("Wait To Shoot") {
	Requires(Robot::shooterWheel);
}
void WaittoShoot::Execute() {
	Robot::shooterWheel->setTargetSpeed(Robot::oi->getSpeedSliderValue());
}
bool WaittoShoot::IsFinished() {
	return Robot::shooterWheel->atTargetSpeed() && Robot::shooter->holdsDisk();
}

// Maintain Speed

MaintainSpeed::MaintainSpeed() :
		CommandStub("Maintain Speed") {
	Requires(Robot::shooterWheel);
}
void MaintainSpeed::Execute() {
	Robot::shooterWheel->setTargetSpeed(Robot::oi->getSpeedSliderValue());
}
