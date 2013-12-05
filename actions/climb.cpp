#include "../actions/climb.h"
#include "../actions/lift.h"
#include "../robot.h"

const double CLIMB_ANGLE = 0.95;

DeploySequence::DeploySequence() :
		CommandGroup("Deploy Sequence") {
	AddParallel(new LockShooterBlob());

	AddSequential(new LiftToTarget(CLIMB_ANGLE));
	AddSequential(new Deploy());

	AddParallel(new LiftTarget(CLIMB_ANGLE));
	AddSequential(new ArmsManual());

	// this command never terminates naturally,
	// but binds up the shooter/lift to prevent accidents
	SetInterruptible(false);
}

ArmsManual::ArmsManual() :
		CommandStub("Arms Manual") {
	Requires(Robot::arms);
}
void ArmsManual::Execute() {
	Robot::arms->setPower(Robot::oi->getClimberPower());
}
void ArmsManual::End() {
	Robot::arms->setPower(0.0);
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

LockShooterBlob::LockShooterBlob() :
		CommandStub("Lock Shooter/Indexer") {
	Requires(Robot::shooter);
	Requires(Robot::shooterWheel);
	Requires(Robot::indexer);
	SetInterruptible(false);
}
void LockShooterBlob::Execute() {
	Robot::shooterWheel->setTargetSpeed(0.0);
	Robot::indexer->Spin(0.0);
}

// Do After Deploy

DoIfDeployed::DoIfDeployed(Command* c) :
		OneShotCommand("Do If Deployed") {
	tostart = c;
}
void DoIfDeployed::Initialize() {
	if (Robot::deployer->hasDeployed()) {
		tostart->Start();
	}
}
