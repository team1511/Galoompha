#include "SmartDashboard/SmartDashboard.h"

#include "controls.h"
#include "utils/calc.h"

#include "actions/autonomous.h"
#include "actions/drive_tank.h"
#include "actions/index.h"
#include "actions/lift.h"
#include "actions/shoot.h"
#include "actions/debug.h"
#include "actions/climb.h"

#include "robot.h"

void addSD(Command* c) {
	SmartDashboard::PutData(c->GetName(), c);
}

// yes, could implement this via Trigger etc.
class SetEncoder: public OneShotCommand {
private:
	bool vv;
public:
	SetEncoder(bool val) :
		OneShotCommand("Control change") {
		SetRunWhenDisabled(true);
		vv = val;
	}
	virtual void Execute() {
		Robot::shooterWheel->setEncoderBroken(vv);
	}
};
class SetDriveVoltage: public OneShotCommand {
private:
	bool vv;
public:
	SetDriveVoltage(bool val) :
		OneShotCommand("Control change") {
		SetRunWhenDisabled(true);
		vv = val;
	}
	virtual void Execute() {
		Robot::drive->SetVoltageMode(vv);
	}
};

Command* makeDumpIfDeployed() {
	Dump* d = new Dump();
	DoIfDeployed* f = new DoIfDeployed(d);
	return f;
}

OI::OI() :
			leftDrive(1),
			rightDrive(2),
			auxStick(3),
			virtualStick(4),
			// Brokens
			indexBroken(&virtualStick, 1),
			wheelEncBroken(&virtualStick, 2),
			angleBroken(&virtualStick, 3),
			voltageDriveMode(&virtualStick, 4),
			coastMode(&virtualStick, 5),
			climberLimitsBroken(&virtualStick, 6),
			// mysteryButton(
			continuousShooting(&virtualStick, 8),
			// Aux
			shoot(&auxStick, 1), feed(&auxStick, 2),
			climbOverride(&auxStick, 10), dump1(&auxStick, 11),
			deploy(&auxStick, 6),
			// LHS
			driveDebug(&leftDrive, 11), shooterDebug(&leftDrive, 6),
			climberDebug(&leftDrive, 7),
			// RHS
			dump2(&rightDrive, 11) {
	// Process operator interface input here.

	indexBroken.WhileHeld(new IndexManual());
	angleBroken.WhileHeld(new LiftManual());
	coastMode.WhileHeld(new TankDrive(Drive::kCoast));
	wheelEncBroken.WhenPressed(new SetEncoder(true));
	wheelEncBroken.WhenReleased(new SetEncoder(false));
	voltageDriveMode.WhenPressed(new SetDriveVoltage(true));
	voltageDriveMode.WhenReleased(new SetDriveVoltage(false));
	voltageDriveMode.WhenPressed(new PrintCommand("VOLT!"));
	
	shoot.WhileHeld(new ShootDisk());
	feed.WhileHeld(new LiftFeed());
	climbOverride.WhileHeld(new ArmsManual());

	dump1.WhenPressed(new DoIfDeployed(new Dump()));
	dump2.WhenPressed(new DoIfDeployed(new Dump()));
	deploy.WhenPressed(new DeploySequence());

	driveDebug.WhileHeld(new DebugDrive());
	shooterDebug.WhileHeld(new DebugShooter());
	climberDebug.WhileHeld(new DebugClimber());

	// SmartDashboard Buttons
	addSD(new AutonBackToHigh());
	addSD(new AutonFrontCenterToHigh());
	addSD(new AutonBackToMid());
	addSD(new AutonNull());

	addSD(new LiftFeed());
	addSD(new LiftStatic());
	addSD(new LiftManual());

	addSD(new IndexIn());
	addSD(new IndexCycle());
	addSD(new IndexManual());
	addSD(new IndexFull());

	addSD(new TankDrive(Drive::kBrake));
	addSD(new TankDrive(Drive::kCoast));

	addSD(new DebugNothing());
	addSD(new DebugClimber());
	addSD(new DebugShooter());
	addSD(new DebugDrive());

	addSD(new ShootDisk());
	addSD(new MoveBlocker(MoveBlocker::kClear));
	addSD(new MoveBlocker(MoveBlocker::kBlock));
	addSD(new MoveKicker(MoveKicker::kKick));
	addSD(new MoveKicker(MoveKicker::kRetract));
	addSD(new WaittoShoot());
	addSD(new MaintainSpeed());
	addSD(new ShooterIdle());

	addSD(new DeploySequence());
	addSD(new ArmsManual());
	addSD(new Dump());
	addSD(new DoIfDeployed(new Dump()));
	addSD(new Deploy());
	addSD(new LockShooterBlob());
}

double getDrivePower(Joystick* stick) {
	double input = stick->GetY();
	bool turbo = stick->GetRawButton(1);
	bool slow = stick->GetRawButton(2);
	return powerJoystickCurve(input, slow, turbo);
}

double OI::getLeftDrivePower() {
	return getDrivePower(&leftDrive);
}

double OI::getRightDrivePower() {
	return getDrivePower(&rightDrive);
}

double OI::getSpeedSliderValue() {
	double slider = virtualStick.GetX();
	return linearRangeScale(slider, -1.0f, 1.0f, 0.3f, 1.0f);
}

double OI::getAngleSliderValue() {
	double pre = -1 * virtualStick.GetY();
	return pre;
}

double OI::getIndexManualPower() {
	return auxStick.GetX(GenericHID::kRightHand);
}

double OI::getClimberPower() {
	return -1 * auxStick.GetY();
}

bool OI::getClimberLimitsBroken() {
	return climberLimitsBroken.Get();
}

bool OI::getContinuousShooting() {
	return continuousShooting.Get();
}

bool OI::getDriveOnVoltage() {
	return voltageDriveMode.Get();
}

bool OI::getCoastMode() {
	return coastMode.Get();
}
