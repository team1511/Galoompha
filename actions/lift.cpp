#include "actions/lift.h"
#include "robot.h"
#include "PIDController.h"

#define ANGLE_FEED 0.44f

#define ANGLE_PID_P 2.0
#define ANGLE_PID_I 0.0
#define ANGLE_PID_D 0.0
#define ANGLE_PID_PERIOD 0.020

// Lift Manual

LiftManual::LiftManual() :
		CommandStub("Lift Manual") {
	Requires(Robot::anglingTool);
}

void LiftManual::Execute() {
	double slider = Robot::oi->getAngleSliderValue();

	if (slider < 0.2f && slider > -0.2f) {
		Robot::anglingTool->setSpeed(0.0);
	} else {
		Robot::anglingTool->setSpeed(slider * 0.5);
	}
}

// Lift Static

LiftStatic::LiftStatic() :
		PIDCommandStub("Lift Static", ANGLE_PID_P, ANGLE_PID_I, ANGLE_PID_D,
		ANGLE_PID_PERIOD) {
	Requires(Robot::anglingTool);
}
void LiftStatic::Execute() {
	GetPIDController()->SetSetpoint(Robot::oi->getAngleSliderValue());
}
double LiftStatic::ReturnPIDInput() {
	return Robot::anglingTool->getAngle();
}
void LiftStatic::UsePIDOutput(double output) {
	Robot::anglingTool->setSpeed(output);
}

// Lift Target

LiftTarget::LiftTarget(double angle) :
		PIDCommand("Lift Target", ANGLE_PID_P, ANGLE_PID_I, ANGLE_PID_D,
		ANGLE_PID_PERIOD) {
	Requires(Robot::anglingTool);
	GetPIDController()->SetSetpoint(angle);
}
LiftTarget::LiftTarget(const char* name, double angle) :
		PIDCommand(name, ANGLE_PID_P, ANGLE_PID_I, ANGLE_PID_D,
		ANGLE_PID_PERIOD) {
	Requires(Robot::anglingTool);
	GetPIDController()->SetSetpoint(angle);
}
double LiftTarget::ReturnPIDInput() {
	return Robot::anglingTool->getAngle();
}
void LiftTarget::UsePIDOutput(double output) {
	Robot::anglingTool->setSpeed(output);
}

// Lift To Target

LiftToTarget::LiftToTarget(double angle) :
		LiftTarget(angle) {
}
bool LiftToTarget::IsFinished() {
	double delta = Robot::anglingTool->getAngle()
			- GetPIDController()->GetSetpoint();
	return (delta > -0.05 && delta < 0.05);
}

// Lift Feed

LiftFeed::LiftFeed() :
		LiftTarget("Lift Feed", ANGLE_FEED) {
}
