#include "systems/lift.h"
#include "actions/lift.h"
#include "utils/calc.h"
#include "robot.h"

//absolute limits for the pot on the angle controller
#define ANGLEPOT_MAX 1.2f
#define ANGLEPOT_MIN 0.45f

AnglingTool::AnglingTool() : Subsystem("AnglingTool") {
	anglePot = RobotMap::anglingToolAnglePot;
	liftLeadscrew = RobotMap::anglingToolLiftLeadscrew;
}
    
void AnglingTool::InitDefaultCommand() {
	SetDefaultCommand(new LiftStatic());
}

// TODO: find out if we need to enforce a minimum nonzero speed, to prevent
// stalling motor at very low input
void AnglingTool::setSpeed(float speed) {
	liftLeadscrew->Set(speed);
}
float AnglingTool::getAngle() {
	float voltage = anglePot->GetVoltage();
	float target = linearRangeScale(voltage, ANGLEPOT_MIN, ANGLEPOT_MAX, -1.0, 1.0);
	return target;
}