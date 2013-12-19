#include "../actions/debug.h"
#include "../robot.h"

char b2c(bool b) {
	return b ? 'Y' : 'N';
}

DebugNothing::DebugNothing() :
		CommandStub("Debug Nothing") {
	Requires(Robot::debug);
	SetRunWhenDisabled(true);
}
void DebugNothing::Initialize() {
	DebugWriter().clear();
}

DebugShooter::DebugShooter() :
		CommandStub("Debug Shooter") {
	Requires(Robot::debug);
	SetRunWhenDisabled(true);
}
void DebugShooter::Execute() {
	DebugWriter d;
	ShooterOther* s = Robot::shooter;
	ShooterWheel* w = Robot::shooterWheel;
	AnglingTool* a = Robot::anglingTool;
	Indexer* i = Robot::indexer;
	d.line1("Spd I%0.2f A%0.2f W%.2f", i->getSpeed(), a->getSpeed(),
			w->getSpeed());
	d.line2("Cur I%2.1f A%2.1f W%2.1f", i->getCurrent(), a->getCurrent(),
			w->getCurrent());
	d.line3("Target %.3f", w->getTarget());
	d.line4("Angle %.3f", a->getAngle());
	d.line5("Full %c", b2c(s->holdsDisk()));
	d.line6("Block %c Kick %c", b2c(s->isBlockerUp()), b2c(s->isKickerOut()));
}

DebugDrive::DebugDrive() :
		CommandStub("Debug Drive") {
	Requires(Robot::debug);
	SetRunWhenDisabled(true);
}
void DebugDrive::Execute() {
	DebugWriter d;
	Drive* r = Robot::drive;
	d.line1("Type | Left | Right ");
	d.line2("Pow %1.5f %1.5f", r->getLeftPower(), r->getRightPower());
	d.line3("Cur %2.4f %2.4f", r->getLeftCurrent(), r->getRightCurrent());
	d.line4("Spd %2.4f %2.4f", r->getLeftSpeed(), r->getRightSpeed());
	
	d.line5("Volt %c", b2c(r->isVoltaging()));
	d.line6("Coast %c", b2c(Robot::oi->getCoastMode()));
}

DebugClimber::DebugClimber() :
		CommandStub("Debug Climber") {
	Requires(Robot::debug);
	SetRunWhenDisabled(true);
}
void DebugClimber::Execute() {
	DebugWriter d;
	Arms* a = Robot::arms;
	Dumper* u = Robot::dumper;
	Deployer* p = Robot::deployer;
	d.line1("Top %c Bot %c Spd %1.3f", b2c(a->hitTopLimit()),
			b2c(a->hitBottomLimit()), a->getGoal());
	d.line2("DumpSrv %1.3f", u->getPos());
	d.line3("DeplSrv %1.3f", p->getPos());
	d.line4("ArmCur %2.2f", a->getCurrent());
	d.line5("ArmOut %1.3f", a->getOutput());
}
