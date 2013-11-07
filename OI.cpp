// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DropBlocker.h"
#include "Commands/IndexCycle.h"
#include "Commands/IndexFull.h"
#include "Commands/IndexIn.h"
#include "Commands/IndexManual.h"
#include "Commands/LiftFeed.h"
#include "Commands/LiftManual.h"
#include "Commands/LiftStatic.h"
#include "Commands/MoveKickerForward.h"
#include "Commands/PostKickWait.h"
#include "Commands/RaiseBlocker.h"
#include "Commands/ReadDebug.h"
#include "Commands/RetractKicker.h"
#include "Commands/ShootDisk.h"
#include "Commands/ShooterIdle.h"
#include "Commands/WaittoShoot.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	virtualStick = new Joystick(4);
	
	indexBroken = new JoystickButton(virtualStick, 1);
	indexBroken->WhileHeld(new IndexManual());
	angleBroken = new JoystickButton(virtualStick, 3);
	angleBroken->WhileHeld(new LiftManual());
	auxStick = new Joystick(3);
	
	shootButton = new JoystickButton(auxStick, 1);
	shootButton->WhileHeld(new ShootDisk());
	feedButton = new JoystickButton(auxStick, 2);
	feedButton->WhileHeld(new LiftFeed());
	rightDrive = new Joystick(2);
	
	leftDrive = new Joystick(1);
	
     
        // SmartDashboard Buttons
	SmartDashboard::PutData("Read Debug", new ReadDebug());
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
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
	SmartDashboard::PutData("Post Kick Wait", new PostKickWait());
	SmartDashboard::PutData("Raise Blocker", new RaiseBlocker());
	SmartDashboard::PutData("Shooter Idle", new ShooterIdle());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
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
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
