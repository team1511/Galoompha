#include "SmartDashboard/SmartDashboard.h"

#include "controls.h"
#include "utils/calc.h"

#include "actions/autonomous.h"
#include "actions/drive_tank.h"
#include "actions/index.h"
#include "actions/lift.h"
#include "actions/shoot.h"
#include "actions/debug.h"

void addSD(Command* c) {
	SmardDashboard::PutData(c->GetName(), c);
}
void addSD(Command* c, const char* name) {
	SmardDashboard::PutData(name, c);
}

OI::OI() {
	// Process operator interface input here.

	virtualStick = new Joystick(4);
	indexBroken = new JoystickButton(virtualStick, 1);
	indexBroken->WhileHeld(new IndexManual());
	angleBroken = new JoystickButton(virtualStick, 3);
	angleBroken->WhileHeld(new LiftManual());
	coastMode = new JoystickButton(virtualStick, 5);
	coastMode->WhileHeld(new TankDrive(Drive::kCoast));

	auxStick = new Joystick(3);
	shootButton = new JoystickButton(auxStick, 1);
	shootButton->WhileHeld(new ShootDisk());
	feedButton = new JoystickButton(auxStick, 2);
	feedButton->WhileHeld(new LiftFeed());

	rightDrive = new Joystick(2);

	leftDrive = new Joystick(1);
	driveDebug = new JoystickButton(leftDrive, 11);
	driveDebug->WhileHeld(new DebugDrive());
	shooterDebug = new JoystickButton(leftDrive, 6);
	shooterDebug->WhileHeld(new DebugShooter());
	climberDebug = new JoystickButton(leftDrive, 7);
	climberDebug->WhileHeld(new DebugClimber());

	// SmartDashboard Buttons
	addSD(new AutonRoutine());

	addSD(new LiftFeed());
	addSD(new LiftStatic());
	addSD(new LiftManual());

	addSD(new IndexIn());
	addSD(new IndexCycle());
	addSD(new IndexManual());
	addSD(new IndexFull());

	addSD(new ShootDisk());
	addSD(new RaiseBlocker());
	addSD(new DropBlocker());
	addSD(new MoveKickerForward());
	addSD(new RetractKicker());
	addSD(new WaittoShoot());
	addSD(new MaintainSpeed());
	addSD(new ShooterIdle());

	addSD(new ShooterIdle());
	addSD(new ShooterIdle());

	addSD(new ShooterIdle());
	addSD(new ShooterIdle());
	addSD(new TankDrive(Drive::kBrake));
	addSD(new TankDrive(Drive::kCoast));

	addSD(new DebugNothing());
	addSD(new DebugClimber());
	addSD(new DebugShooter());
	addSD(new DebugDrive());
}

double getDrivePower(Joystick* stick) {
	double input = stick->GetY();
	bool slow = stick->GetRawButton(1);
	bool turbo = stick->GetRawButton(2);
	return powerJoystickCurve(input, slow, turbo);
}

double OI::getLeftDrivePower() {
	return getDrivePower(leftDrive);
}

double OI::getRightDrivePower() {
	return getDrivePower(rightDrive);
}

double OI::getSpeedSliderValue() {
	float slider = virtualStick->GetX();
	float speed = linearRangeScale(slider, -1.0f, 1.0f, 0.3f, 1.0f);
	return speed;
}

double OI::getAngleSliderValue() {
	double pre = -1 * virtualStick->GetY();
	return pre;
}

double OI::getIndexManualPower() {
	return auxStick->GetX(GenericHID::kRightHand);
}
                             
