#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/Autonomous.h"
#include "Commands/DropBlocker.h"
#include "Commands/IndexCycle.h"
#include "Commands/IndexFull.h"
#include "Commands/IndexIn.h"
#include "Commands/IndexManual.h"
#include "Commands/LiftFeed.h"
#include "Commands/LiftManual.h"
#include "Commands/LiftStatic.h"
#include "Commands/LiftTarget.h"
#include "Commands/MoveKickerForward.h"
#include "Commands/RaiseBlocker.h"
#include "Commands/RetractKicker.h"
#include "Commands/ShootDisk.h"
#include "Commands/ShooterIdle.h"
#include "Commands/WaittoShoot.h"
#include "Commands/MaintainSpeed.h"
#include "Commands/TankDrive.h"

OI::OI() {
	// Process operator interface input here.

	virtualStick = new Joystick(4);
	indexBroken = new JoystickButton(virtualStick, 1);
	indexBroken->WhileHeld(new IndexManual());
	angleBroken = new JoystickButton(virtualStick, 3);
	angleBroken->WhileHeld(new LiftManual());
	coastMode = new JoystickButton(virtualStick, 5);
	coastMode->WhileHeld(new TankDrive(Drive::modeCoast));

	auxStick = new Joystick(3);
	shootButton = new JoystickButton(auxStick, 1);
	shootButton->WhileHeld(new ShootDisk());
	feedButton = new JoystickButton(auxStick, 2);
	feedButton->WhileHeld(new LiftFeed());

	rightDrive = new Joystick(2);

	leftDrive = new Joystick(1);

	// SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous", new Autonomous());
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
			new TankDrive(Drive::modeCoast));
	SmartDashboard::PutData("Tank Drive: Brake",
			new TankDrive(Drive::modeBrake));

}
Joystick* OI::getVirtualStick() {
	return virtualStick;
}
Joystick* OI::getAuxStick() {
	return auxStick;
}
Joystick* OI::getRightDrive() {
	return rightDrive;
}
Joystick* OI::getLeftDrive() {
	return leftDrive;
}
