// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
CANJaguar* RobotMap::indexerIndexerWheel = NULL;
DigitalInput* RobotMap::shooterLoadSensor = NULL;
CANJaguar* RobotMap::shooterShooterWheel = NULL;
Servo* RobotMap::shooterKicker = NULL;
Servo* RobotMap::shooterBlocker = NULL;
AnalogChannel* RobotMap::anglingToolAnglePot = NULL;
CANJaguar* RobotMap::anglingToolLiftLeadscrew = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
void RobotMap::init() {
	LiveWindow* lw = LiveWindow::GetInstance();
	indexerIndexerWheel = new CANJaguar(10);
	
	
	shooterLoadSensor = new DigitalInput(1, 14);
	lw->AddSensor("Shooter Other", "Load Sensor", shooterLoadSensor);
	
	shooterShooterWheel = new CANJaguar(8);
	lw->AddActuator("Shooter Wheel", "Wheel", shooterShooterWheel);
	
	shooterKicker = new Servo(1, 5);
	lw->AddActuator("Shooter Other", "Kicker", shooterKicker);
	
	shooterBlocker = new Servo(1, 4);
	lw->AddActuator("Shooter Other", "Blocker", shooterBlocker);
	
	anglingToolAnglePot = new AnalogChannel(1, 6);
	lw->AddSensor("Angling Tool", "Angle Pot", anglingToolAnglePot);
	
	anglingToolLiftLeadscrew = new CANJaguar(9);
	
	
}
