#include "actions/autonomous.h"
#include "actions/shoot.h"
#include "actions/lift.h"

const double ANGLE_B2H = -0.93;
const double POWER_B2H = 0.63;

const double ANGLE_B2M = -0.85;
const double POWER_B2M = 0.58;

const double ANGLE_F2H = -0.35;
const double POWER_F2H = 0.58;

Generic3ShotAuton::Generic3ShotAuton(const char* name, double angle,
		double power) :
		CommandGroup(name) {
	AddSequential(new LiftToTarget(angle));
	AddSequential(new ShootDisk(ShooterWheel::kCustom, power));
	AddSequential(new ShootDisk(ShooterWheel::kCustom, power));
	AddSequential(new ShootDisk(ShooterWheel::kCustom, power));
}

AutonBackToHigh::AutonBackToHigh() :
		Generic3ShotAuton("Auton: Back To High", ANGLE_B2H, POWER_B2H) {
}

AutonBackToMid::AutonBackToMid() :
		Generic3ShotAuton("Auton: Back To Mid", ANGLE_B2M, POWER_B2M) {
}

AutonFrontCenterToHigh::AutonFrontCenterToHigh() :
		Generic3ShotAuton("Auton: Front Center To High", ANGLE_F2H, POWER_F2H) {
}

AutonNull::AutonNull() : OneShotCommand("Auton: No Action") {
}
