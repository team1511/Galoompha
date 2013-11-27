#include "robotmap.h"
#include "LiveWindow/LiveWindow.h"

CANJaguar* RobotMap::indexerIndexerWheel = NULL;
DigitalInput* RobotMap::shooterLoadSensor = NULL;
CANJaguar* RobotMap::shooterShooterWheel = NULL;
Servo* RobotMap::shooterKicker = NULL;
Servo* RobotMap::shooterBlocker = NULL;
AnalogChannel* RobotMap::anglingToolAnglePot = NULL;
CANJaguar* RobotMap::anglingToolLiftLeadscrew = NULL;
MonoEncoder* RobotMap::shooterEncoder = NULL;
CANJaguar* RobotMap::driveRightMotor = NULL;
CANJaguar* RobotMap::driveLeftMotor = NULL;

void RobotMap::init() {
	LiveWindow* lw = LiveWindow::GetInstance();
	indexerIndexerWheel = new CANJaguar(10);
	lw->AddActuator("Indexer", "Indexer Wheel", indexerIndexerWheel);

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
	lw->AddActuator("Angling Tool", "Lift Leadscrew", indexerIndexerWheel);

	shooterEncoder = new MonoEncoder(5, 82, 250);
	lw->AddSensor("Shooter Wheel", "Encoder", shooterEncoder);

	driveRightMotor = new CANJaguar(4);
	driveLeftMotor = new CANJaguar(2);
	lw->AddActuator("Drive", "Right Motor", driveRightMotor);
	lw->AddActuator("Drive", "Left Motor", driveLeftMotor);

	driveLeftEncoder = new MonoEncoder(1, 1.0, 42);
	lw->AddActuator("Drive", "Left Encoder", driveLeftEncoder);

	driveRightEncoder = new MonoEncoder(3, 1.0, 42);
	lw->AddActuator("Drive", "Right Encoder", driveLeftEncoder);
}
