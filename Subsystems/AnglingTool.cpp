#include "AnglingTool.h"
#include "../Robotmap.h"
#include "../Commands/LiftStatic.h"
#include "../Calc.h"

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
// Put methods for controlling this subsystem
// here. Call these from Commands.
void AnglingTool::setSpeed(float speed) {
	liftLeadscrew->Set(speed);
}
float AnglingTool::getAngle() {
	float voltage = anglePot->GetVoltage();
	float target = linearRangeScale(voltage, ANGLEPOT_MIN, ANGLEPOT_MAX, -1.0, 1.0);
	return target;
}
