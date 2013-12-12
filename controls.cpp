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

Command* makeDumpIfDeployed() {
	Dump* d = new Dump();
	DoIfDeployed* f = new DoIfDeployed(d);
	return f;
}

OI::OI() {
	// Process operator interface input here.
	leftDrive = new Joystick(1);
	rightDrive = new Joystick(2);
	auxStick = new Joystick(3);
	virtualStick = new Joystick(4);
	
	indexBroken = new JoystickButton(virtualStick, 1);
	indexBroken->WhileHeld(new IndexManual());
	angleBroken = new JoystickButton(virtualStick, 3);
	angleBroken->WhileHeld(new LiftManual());
	coastMode = new JoystickButton(virtualStick, 5);
	coastMode->WhileHeld(new TankDrive(Drive::kCoast));
	wheelEncBroken = new JoystickButton(virtualStick, 2);
	wheelEncBroken->WhenPressed(new SetEncoder(true));
	wheelEncBroken->WhenReleased(new SetEncoder(false));

	shoot = new JoystickButton(auxStick, 1);
	shoot->WhileHeld(new ShootDisk());
	feed = new JoystickButton(auxStick, 2);
	feed->WhileHeld(new LiftFeed());
	climbOverride = new JoystickButton(auxStick, 10);
	climbOverride->WhileHeld(new ArmsManual());

	dump1 = new JoystickButton(auxStick, 11);
	dump2 = new JoystickButton(rightDrive, 11);
	dump1->WhenPressed(new DoIfDeployed(new Dump()));
	dump2->WhenPressed(new DoIfDeployed(new Dump()));
	deploy = new JoystickButton(auxStick, 6);
	deploy->WhenPressed(new DeploySequence());

	driveDebug = new JoystickButton(leftDrive, 11);
	driveDebug->WhileHeld(new DebugDrive());
	shooterDebug = new JoystickButton(leftDrive, 6);
	shooterDebug->WhileHeld(new DebugShooter());
	climberDebug = new JoystickButton(leftDrive, 7);
	climberDebug->WhileHeld(new DebugClimber());

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
	return getDrivePower(leftDrive);
}

double OI::getRightDrivePower() {
	return getDrivePower(rightDrive);
}

double OI::getSpeedSliderValue() {
	double slider = virtualStick->GetX();
	return linearRangeScale(slider, -1.0f, 1.0f, 0.3f, 1.0f);
}

double OI::getAngleSliderValue() {
	double pre = -1 * virtualStick->GetY();
	return pre;
}

double OI::getIndexManualPower() {
	return auxStick->GetX(GenericHID::kRightHand);
}

double OI::getClimberPower() {
	return -1 * auxStick->GetY();
}

bool OI::getClimberLimitsBroken() {
	return virtualStick->GetRawButton(6);
}

bool OI::getContinuousShooting() {
	return virtualStick->GetRawButton(8);
}

