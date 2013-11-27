#include "actions/debug.h"
#include "robot.h"

DebugNothing::DebugNothing() :
		CommandStub("Debug Nothing") {
	Requires(Robot::debug);
}
void DebugNothing::Initialize() {
	DebugWriter().clear();
}

DebugShooter::DebugShooter() :
		CommandStub("Debug Shooter") {
	Requires(Robot::debug);
}

char b2c(bool b) {
	return b ? "Y" : "N";
}

void DebugShooter::Execute() {
	DebugWriter d;
	ShooterOther* s = Robot::shooter;
	ShooterWheel* w = Robot::shooterWheel;
	AnglingTool* a = Robot::anglingTool;
	Indexer* i = Robot::indexer;
	d.line1("Spd I%0.3f A%0.3f W%.3f", i->getSpeed(), a->getSpeed(),
			w->getSpeed());
	d.line2("Cur I%2.1f A%2.1f W%2.1f", i->getCurrent(), a->getCurrent(),
			w->getCurrent());
	d.line3("Target %.3f", w->getTarget());
	d.line4("Angle %.3f", a->getAngle());
	d.line5("Full %c", b2c(s->holdsDisk()));
	d.line6("Block %c Kick %c", b2c(s->isBlockerUp()),
			b2c(s->isKickerOut()));
}

DebugDrive::DebugDrive() :
		CommandStub("Debug Drive") {
	Requires(Robot::debug);
}
void DebugDrive::Execute() {
	DebugWriter d;
	Drive* r = Robot::drive;
	d.line1("Type | Left | Right ");
	d.line2("Pow %1.5f %1.5f", r->getLeftPower(), r->getRightPower());
	d.line3("Cur %2.4f %2.4f", r->getLeftCurrent(), r->getRightCurrent());
	d.line4("Spd %2.4f %2.4f", r->getLeftSpeed(), r->getRightSpeed());
}

DebugClimber::DebugClimber() :
		CommandStub("Debug Climber") {
	Requires(Robot::debug);
}
void DebugClimber::Execute() {
	DebugWriter d;
}
