#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "utils/mono_encoder.h"

class RobotMap {
public:
	static void init();

	static CANJaguar* indexerIndexerWheel;

	static CANJaguar* shooterWheelMotor;
	static MonoEncoder* shooterWheelEncoder;

	static DigitalInput* shooterLoadSensor;
	static Servo* shooterKicker;
	static Servo* shooterBlocker;

	static AnalogChannel* anglingToolAnglePot;
	static CANJaguar* anglingToolLiftLeadscrew;

	static CANJaguar* driveRightMotor;
	static CANJaguar* driveLeftMotor;
	static MonoEncoder* driveLeftEncoder;
	static MonoEncoder* driveRightEncoder;

	static DigitalInput* climberTopLimit;
	static DigitalInput* climberBottomLimit;
	static CANJaguar* climberMotor;

	static Servo* dumperServo;

	static Servo* deployerServo;
};
#endif
