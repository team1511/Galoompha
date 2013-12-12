#include "../actions/lift.h"
#include "../robot.h"
#include "PIDController.h"

const double ANGLE_FEED = 0.44;

const double ANGLE_PID_P = 2.0;
const double ANGLE_PID_I = 0.0;
const double ANGLE_PID_D = 0.0;
const double ANGLE_PID_PERIOD = 0.020;

const double ANGLE_CLOSE = 0.05;

// Lift Manual

LiftManual::LiftManual() :
	CommandStub("Lift Manual") {
	Requires(Robot::anglingTool);
	Requires(Robot::lights);
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
			PIDCommandStub("Lift Static", ANGLE_PID_P, ANGLE_PID_I,
					ANGLE_PID_D, ANGLE_PID_PERIOD) {
	Requires(Robot::anglingTool);
	Requires(Robot::lights);
}
void LiftStatic::Initialize() {
	Robot::lights->setFeed(Lights::kNone);
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
			PIDCommandStub("Lift Target", ANGLE_PID_P, ANGLE_PID_I,
					ANGLE_PID_D, ANGLE_PID_PERIOD) {
	Requires(Robot::anglingTool);
	Requires(Robot::lights);
	GetPIDController()->SetSetpoint(angle);
}
LiftTarget::LiftTarget(const char* name, double angle) :
			PIDCommandStub(name, ANGLE_PID_P, ANGLE_PID_I, ANGLE_PID_D,
					ANGLE_PID_PERIOD) {
	Requires(Robot::anglingTool);
	Requires(Robot::lights);
	GetPIDController()->SetSetpoint(angle);
}
double LiftTarget::ReturnPIDInput() {
	return Robot::anglingTool->getAngle();
}
void LiftTarget::UsePIDOutput(double output) {
	Robot::anglingTool->setSpeed(output);
}
bool LiftTarget::OnTarget() {
	double delta = Robot::anglingTool->getAngle()
			- GetPIDController()->GetSetpoint();
	return (delta > -ANGLE_CLOSE && delta < ANGLE_CLOSE);	
}

// Lift To Target

LiftToTarget::LiftToTarget(double angle) :
	LiftTarget(angle) {
}
bool LiftToTarget::IsFinished() {
	return OnTarget();
}

// Lift Feed

LiftFeed::LiftFeed() :
	LiftTarget("Lift Feed", ANGLE_FEED) {
}
void LiftFeed::Initialize() {
	Robot::lights->setFeed(Lights::kLifting);
}
void LiftFeed::Execute() {
	Robot::lights->setFeed(OnTarget() ? Lights::kReady : Lights::kLifting);
}
void LiftFeed::End() {
	LiftTarget::End();
	Robot::lights->setFeed(Lights::kNone);
}
void LiftFeed::Interrupted() {
	LiftTarget::Interrupted();
	Robot::lights->setFeed(Lights::kNone);
}
