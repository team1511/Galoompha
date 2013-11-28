#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "utils/mono_encoder.h"
/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	static CANJaguar* indexerIndexerWheel;
	static DigitalInput* shooterLoadSensor;
	static CANJaguar* shooterShooterWheel;
	static Servo* shooterKicker;
	static Servo* shooterBlocker;
	static AnalogChannel* anglingToolAnglePot;
	static CANJaguar* anglingToolLiftLeadscrew;
	static MonoEncoder* shooterEncoder;
	static CANJaguar* driveRightMotor;
	static CANJaguar* driveLeftMotor;
	static MonoEncoder* driveLeftEncoder;
	static MonoEncoder* driveRightEncoder;
	static DigitalInput* climberTopLimit;
	static DigitalInput* climberBottomLimit;
	static CANJaguar* climberMotor;
	static Servo* dumperServo;
	static Servo* deployerServo;
	static void init();
};
#endif
