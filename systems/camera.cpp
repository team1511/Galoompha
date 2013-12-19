#include "../systems/camera.h"
#include "../robotmap.h"
#include "../actions/cameratilt.h"

CameraTilter::CameraTilter() :
	Subsystem("CameraTilter") {
	servo = RobotMap::cameraServo;
}
void CameraTilter::InitDefaultCommand() {
	SetDefaultCommand(new CameraShootMode());
}
void CameraTilter::tiltToAngle(double angle) {
	servo->SetAngle(angle);
}
double CameraTilter::getAngle() {
	return servo->GetAngle();
}


