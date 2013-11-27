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
	float slider = Robot::oi->getAngleSliderValue();

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

	if (!GetPIDController()->IsEnabled()) {
		printf("Enabling STATIC\n");
		GetPIDController()->Enable();
	}
}
// this function MAY NEVER call PIDController::GetError()
double LiftStatic::ReturnPIDInput() {
	// if this code were in UsePIDOutput, the call
	// to Disable would call UsePIDOutput. to infinite loop.
	if (Robot::getInstance().IsDisabled()) {
		printf("Disabling STATIC\n");
		GetPIDController()->Reset();
	}
	return Robot::anglingTool->getAngle();
}
void LiftStatic::UsePIDOutput(double output) {
	Robot::anglingTool->setSpeed(output);
}

// Lift Target

LiftTarget::LiftTarget(float angle) :
		PIDCommand("Lift Target", ANGLE_PID_P, ANGLE_PID_I, ANGLE_PID_D,
				ANGLE_PID_PERIOD) {
	Requires(Robot::anglingTool);
	GetPIDController()->SetSetpoint(angle);
}

LiftTarget::LiftTarget(const char* name, float angle) :
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

// Lift Feed

LiftFeed::LiftFeed() : LiftTarget("Lift Feed", ANGLE_FEED) {
}
