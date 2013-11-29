#include "actions/climb.h"
#include "actions/lift.h"

#define CLIMB_ANGLE 0.95

DeploySequence::DeploySequence() :
		CommandGroup("Deploy Sequence") {
	AddParallel(new LockShooter());

	AddSequential(new LiftToTarget(CLIMB_ANGLE));
	AddSequential(new Deploy());

	AddParallel(new LockLift());
	AddParallel(new LockIndexer());
	// never terminates: mode lasts indefinitely, as it should
	AddSequential(new ArmsManual());

	SetInterruptible(false);
	// we could use Requires on the three subsystems we want
	// to disable, but the LockX commands also ensure they
	// stop moving.
}

ArmsManual::ArmsManual() :
		CommandStub("Arms Manual") {
	Requires(Robot::arms);
}
void ArmsManual::Execute() {
	Robot::arms->setPower(Robot::oi->getClimberPower());
}

// Actions.

Dump::Dump() :
		OneShotCommand("Dump") {
	Requires(Robot::dumper);
}
void Dump::Execute() {
	Robot::dumper->dump(true);
}

Deploy::Deploy() :
		OneShotCommand("Deploy") {
	Requires(Robot::deployer);
}
void Deploy::Execute() {
	Robot::deployer->deploy(true);
}

// Lock all shooter systems

LockShooter::LockShooter() :
		CommandStub("Lock Shooter") {
	Requires(Robot::shooter);
	Requires(Robot::shooterWheel);
	SetInterruptible(false);
}
void LockShooter::Execute() {
	Robot::shooterWheel->setTargetSpeed(0.0);
}
LockLift::LockLift() :
		CommandStub("Lock Shooter") {
	Requires(Robot::anglingTool);
	SetInterruptible(false);
}
void LockLift::Execute() {
	Robot::anglingTool->setSpeed(0.0);
}
LockIndexer::LockIndexer() :
		CommandStub("Lock Shooter") {
	Requires(Robot::indexer);
	SetInterruptible(false);
}
void LockIndexer::Execute() {
	Robot::indexer->Spin(0.0);
}

