#include "../utils/pid_command_stub.h"
#include "PIDController.h"

PIDCommandStub::PIDCommandStub(const char* name, double p, double i, double d,
		double period) :
		PIDCommand(name, p, i, d, period) {
}

/**
 * Default: reset and enable the controller
 */
void PIDCommandStub::Initialize() {
	GetPIDController()->Reset();
	GetPIDController()->Enable();
}
/**
 * Default: no action
 */
void PIDCommandStub::Execute() {
}
/**
 * Default: never finishes
 */
bool PIDCommandStub::IsFinished() {
	return false;
}
/**
 * Default: disable controller
 */
void PIDCommandStub::End() {
	GetPIDController()->Disable();
}
/**
 * Default: disable controller
 */
void PIDCommandStub::Interrupted() {
	GetPIDController()->Disable();
}
