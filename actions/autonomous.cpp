#include "actions/autonomous.h"
#include "actions/shoot.h"
#include "actions/lift.h"

// far corner to high goal
#define SHOOT_ANGLE		-0.93
#define SHOOT_POWER		0.63

AutonRoutine::AutonRoutine() {
	AddSequential(new LiftToTarget(SHOOT_ANGLE));
	AddSequential(new ShootDisk());
	AddSequential(new ShootDisk());
	AddSequential(new ShootDisk());
}
