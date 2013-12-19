#include "../actions/cameratilt.h"
#include "../robot.h"
#include "../utils/calc.h"

const double S_MIN = 0;
const double S_MAX = 1.0;
const double S_STEP = 0.01;

CameraShootMode::CameraShootMode() :
	CommandStub("Camera Shoot Mode") {
	Requires(Robot::cameraTilt);
}

void CameraShootMode::Initialize() {
	angle = bound(Robot::cameraTilt->getAngle(), S_MIN, S_MAX);
}

void CameraShootMode::Execute() {
	bool up = Robot::oi->getCameraUp();
	bool down = Robot::oi->getCameraDown();
	if (up && !down) {
		angle = bound(angle + S_STEP, S_MIN, S_MAX);
	}
	if (down && !up) {
		angle = bound(angle - S_STEP, S_MIN, S_MAX);
	}
	Robot::cameraTilt->tiltToAngle(angle);
}

const double C_MIN = 0;
const double C_MAX = 1.0;
const double C_STEP = 0.01;

CameraClimbMode::CameraClimbMode() :
	CommandStub("Camera Shoot Mode") {
	Requires(Robot::cameraTilt);
}

void CameraClimbMode::Initialize() {
	angle = bound(Robot::cameraTilt->getAngle(), C_MIN, C_MAX);
}

void CameraClimbMode::Execute() {
	bool up = Robot::oi->getCameraUp();
	bool down = Robot::oi->getCameraDown();
	if (up && !down) {
		angle = bound(angle + C_STEP, C_MIN, C_MAX);
	}
	if (down && !up) {
		angle = bound(angle - C_STEP, C_MIN, C_MAX);
	}
	Robot::cameraTilt->tiltToAngle(angle);
}
