#include "SmartDashboard/SmartDashboard.h"

#include "controls.h"
#include "utils/calc.h"

#include "actions/autonomous.h"
#include "actions/drive_tank.h"
#include "actions/index.h"
#include "actions/lift.h"
#include "actions/shoot.h"

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

	// SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous", new AutonRoutine());
	SmartDashboard::PutData("LiftFeed", new LiftFeed());
	SmartDashboard::PutData("Index In", new IndexIn());
	SmartDashboard::PutData("Index Cycle", new IndexCycle());
	SmartDashboard::PutData("Index Full", new IndexFull());
	SmartDashboard::PutData("Index Manual", new IndexManual());
	SmartDashboard::PutData("Lift Feed", new LiftFeed());
	SmartDashboard::PutData("Lift Static", new LiftStatic());
	SmartDashboard::PutData("Lift Manual", new LiftManual());
	SmartDashboard::PutData("Wait to Shoot", new WaittoShoot());
	SmartDashboard::PutData("Drop Blocker", new DropBlocker());
	SmartDashboard::PutData("Shoot Disk", new ShootDisk());
	SmartDashboard::PutData("Move Kicker Forward", new MoveKickerForward());
	SmartDashboard::PutData("Retract Kicker", new RetractKicker());
	SmartDashboard::PutData("Raise Blocker", new RaiseBlocker());
	SmartDashboard::PutData("Shooter Idle", new ShooterIdle());
	SmartDashboard::PutData("Maintain Speed", new MaintainSpeed());
	SmartDashboard::PutData("Tank Drive: Coast",
			new TankDrive(Drive::kCoast));
	SmartDashboard::PutData("Tank Drive: Brake",
			new TankDrive(Drive::kBrake));
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
                             
