#include "actions/climb.h"
#include "actions/lift.h"

#define CLIMB_ANGLE 0.95

DeploySequence::DeploySequence() :
		CommandGroup("Deploy Sequence") {
	AddParallel(new LockShooter());

	AddSequential(new LiftToTarget(CLIMB_ANGLE));
	AddSequential(new Deploy());

	AddParallel(new UnlockDumper());
	AddParallel(new LockLift())
	AddParallel(new LockIndexer());
	AddSequential(new ArmsManual());

	SetInterruptible(false);
}

ArmsRest::ArmsRest() :
		CommandStub("Arms Rest") {
	Requires(Robot::arms);
}
ArmsManual::ArmsManual() :
		CommandStub("Arms Manual") {
	Requires(Robot::arms);
}
void ArmsManual::Execute() {
	Robot::arms->setPower(Robot::oi->getClimberPower());
}


// Dumper/Deployer Rests: default states

DumperRest::DumperRest() :
		CommandStub("Dumper Rest") {
	Requires(Robot::dumper);
}
void DumperRest::Initialize() {
	Robot::dumper->lock(true);
}
void DumperRest::End() {
	Robot::dumper->Dumper(false);
}

DeployerRest::DeployerRest() :
		CommandStub("Deployer Rest") {
	Requires(Robot::deployer);
}
void DeployerRest::End() {
	Robot::deployer->deploy(false);
}

// Actions. When forced out by scheduler, they
// reset to a safe state

Dump::Dump() :
		CommandStub("Dump") {
	Requires(Robot::dumper);
}
void Dump::Initialize() {
	// ooh, what happens if we cancel ourselves?
}
void Dump::Execute() {
	if (!Robot::dumper->isLocked()) {
		Robot::dumper->dump(true);
	}
}
bool Dump::IsFinished() {
	return Robot::dumper->isLocked();
}
void Dump::End() {
	Robot::dumper->dump(false);
}

Deploy::Deploy() :
		CommandStub("Deploy") {
	Requires(Robot::deployer);
}
void Deploy::Execute() {
	Robot::deployer->deploy(true);
}
void Deploy::End() {
	Robot::deployer->deploy(false);
}

// manage dumper state

UnlockDumper::UnlockDumper() :
		OneShotCommand("Deploy") {
	Requires(Robot::dumper);
}
void UnlockDumper::Execute() {
	Robot::dumper->lock(false);
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

