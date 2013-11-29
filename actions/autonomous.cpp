#include "actions/autonomous.h"
#include "actions/shoot.h"
#include "actions/lift.h"

const double ANGLE_B2H = -0.93;
const double POWER_B2H = 0.63;

const double ANGLE_B2M = -0.85;
const double POWER_B2M = 0.58;

const double ANGLE_F2H = -0.35;
const double POWER_F2H = 0.58;

// yes, AutonSwitcher is not memory-safe.
// would need to go CommandGroup style (assume requirements, mirror End/Interrupted...)
AutonSwitcher::AutonSwitcher() :
		OneShotCommand("Auton Switcher"), //
		b2h("Back To High", ANGLE_B2H, POWER_B2H), //
		b2m("Back To Mid", ANGLE_B2M, POWER_B2M), //
		fc2h("Front Center To High", ANGLE_F2H, POWER_F2H) {

}
void AutonSwitcher::Initialize() {
	int choice = 1;
	switch (choice) {
	case 1:
		b2h.Start();
		return;
	case 2:
		b2m.Start();
		return;
	case 3:
		fc2h.Start();
		return;
	default:
		return;
	}
}

Generic3ShotAuton::Generic3ShotAuton(const char* name, double angle,
		double power) :
		CommandGroup(name) {
	AddSequential(new LiftToTarget(angle));
	AddSequential(new ShootDisk(ShooterWheel::kCustom, power));
	AddSequential(new ShootDisk(ShooterWheel::kCustom, power));
	AddSequential(new ShootDisk(ShooterWheel::kCustom, power));
}
