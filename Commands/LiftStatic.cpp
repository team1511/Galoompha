#include "LiftStatic.h"
LiftStatic::LiftStatic() :
		PIDCommand("Lift Static", ANGLE_PID_P, ANGLE_PID_I, ANGLE_PID_D,
				ANGLE_PID_PERIOD) {
	Requires(Robot::anglingTool);
	GetPIDController()->Disable();
}
void LiftStatic::Initialize() {
	GetPIDController()->Reset();
	GetPIDController()->Enable();
}
void LiftStatic::Execute() {
	float slider = Robot::oi->getAngleSliderValue();

	GetPIDController()->SetSetpoint(slider);

	// hackn! to turn pid calculations off while disabled
	if (!GetPIDController()->IsEnabled()) {
		printf("Enabling STATIC\n");
		GetPIDController()->Enable();
	}
}
bool LiftStatic::IsFinished() {
	return false;
}
void LiftStatic::End() {
	GetPIDController()->Disable();
}
void LiftStatic::Interrupted() {
	GetPIDController()->Disable();
}

// this function MAY NEVER call PIDController::GetError()
double LiftStatic::ReturnPIDInput() {
	double v = Robot::anglingTool->getAngle(); 
	
	// if this code were in UsePIDOutput, the call
	// to Disable would call UsePIDOutput. to infinite loop.
	if (Robot::getInstance().IsDisabled()) {
		printf("Disabling STATIC\n");
		GetPIDController()->Reset();
	}
	return v;
}
void LiftStatic::UsePIDOutput(double output) {
	// is it bad for the motor if we write 0.005 AND IT does nothing?
	Robot::anglingTool->setSpeed(output);
}
