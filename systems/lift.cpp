#include "../systems/lift.h"
#include "../actions/lift.h"
#include "../utils/calc.h"
#include "../robot.h"

//absolute limits for the pot on the angle controller
const double ANGLEPOT_MAX = 1.2;
const double ANGLEPOT_MIN = 0.45;

AnglingTool::AnglingTool() :
		Subsystem("AnglingTool") {
	anglePot = RobotMap::anglingToolAnglePot;
	liftLeadscrew = RobotMap::anglingToolLiftLeadscrew;
	speed = 0;
}

void AnglingTool::InitDefaultCommand() {
	SetDefaultCommand(new LiftStatic());
}

// TODO: find out if we need to enforce a minimum nonzero speed, to prevent
// stalling motor at very low input
void AnglingTool::setSpeed(double s) {
	speed = s;
	liftLeadscrew->Set(speed);
}

double AnglingTool::getAngle() {
	double voltage = anglePot->GetVoltage();
	double target = linearRangeScale(voltage, ANGLEPOT_MIN, ANGLEPOT_MAX, -1.0,
			1.0);
	return target;
}

double AnglingTool::getSpeed() {
	return speed;
}

double AnglingTool::getCurrent() {
	return liftLeadscrew->GetOutputCurrent();
}
