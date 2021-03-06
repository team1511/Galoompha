#include "robotmap.h"
#include "LiveWindow/LiveWindow.h"

CANJaguar* RobotMap::indexerIndexerWheel = NULL;

CANJaguar* RobotMap::shooterWheelMotor = NULL;
MonoEncoder* RobotMap::shooterWheelEncoder = NULL;

DigitalInput* RobotMap::shooterLoadSensor = NULL;
Servo* RobotMap::shooterKicker = NULL;
Servo* RobotMap::shooterBlocker = NULL;

AnalogChannel* RobotMap::anglingToolAnglePot = NULL;
CANJaguar* RobotMap::anglingToolLiftLeadscrew = NULL;

CANJaguar* RobotMap::driveRightMotor = NULL;
CANJaguar* RobotMap::driveLeftMotor = NULL;
MonoEncoder* RobotMap::driveLeftEncoder = NULL;
MonoEncoder* RobotMap::driveRightEncoder = NULL;

DigitalInput* RobotMap::climberTopLimit = NULL;
DigitalInput* RobotMap::climberBottomLimit = NULL;
CANJaguar* RobotMap::climberMotor = NULL;

Servo* RobotMap::dumperServo = NULL;

Servo* RobotMap::deployerServo = NULL;

Servo* RobotMap::cameraServo = NULL;

void RobotMap::init() {
	LiveWindow* lw = LiveWindow::GetInstance();
	indexerIndexerWheel = new CANJaguar(10);
	lw->AddActuator("Indexer", "Indexer Wheel", indexerIndexerWheel);

	shooterLoadSensor = new DigitalInput(1, 14);
	lw->AddSensor("Shooter Other", "Load Sensor", shooterLoadSensor);

	shooterWheelMotor = new CANJaguar(8);
	lw->AddActuator("Shooter Wheel", "Wheel", shooterWheelMotor);

	shooterKicker = new Servo(1, 5);
	lw->AddActuator("Shooter Other", "Kicker", shooterKicker);

	shooterBlocker = new Servo(1, 4);
	lw->AddActuator("Shooter Other", "Blocker", shooterBlocker);

	anglingToolAnglePot = new AnalogChannel(1, 6);
	lw->AddSensor("Angling Tool", "Angle Pot", anglingToolAnglePot);

	anglingToolLiftLeadscrew = new CANJaguar(9);
	lw->AddActuator("Angling Tool", "Lift Leadscrew", anglingToolLiftLeadscrew);

	shooterWheelEncoder = new MonoEncoder(5, 82, 250);
	lw->AddSensor("Shooter Wheel", "Encoder", shooterWheelEncoder);

	driveRightMotor = new CANJaguar(4);
	driveLeftMotor = new CANJaguar(2);
	lw->AddActuator("Drive", "Right Motor", driveRightMotor);
	lw->AddActuator("Drive", "Left Motor", driveLeftMotor);

	driveLeftEncoder = new MonoEncoder(1, 1.0, 42);
	driveRightEncoder = new MonoEncoder(3, 1.0, 42);
	lw->AddActuator("Drive", "Left Encoder", driveLeftEncoder);
	lw->AddActuator("Drive", "Right Encoder", driveRightEncoder);

	climberTopLimit = new DigitalInput(9);
	climberBottomLimit = new DigitalInput(10);
	lw->AddActuator("Arms", "Top Limit", climberTopLimit);
	lw->AddActuator("Arms", "Bottom Limit", climberBottomLimit);

	climberMotor = new CANJaguar(7);
	lw->AddActuator("Arms", "Motor", climberMotor);

	dumperServo = new Servo(6);
	lw->AddActuator("Dumper", "Servo", dumperServo);

	deployerServo = new Servo(3);
	lw->AddActuator("Deployer", "Servo", deployerServo);
	
	cameraServo = new Servo(1);
	lw->AddActuator("Camera", "Servo", cameraServo);
}
