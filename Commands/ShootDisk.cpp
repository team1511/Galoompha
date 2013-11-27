#include "ShootDisk.h"
#include "Commands/WaitCommand.h"
#include "MoveKickerForward.h"
#include "RetractKicker.h"
#include "RaiseBlocker.h"
#include "WaitToShoot.h"
#include "DropBlocker.h"
#include "MaintainSpeed.h"

// should these constants really be pulled out?
// this style is rather legible...
#define DROP_TIME 0.5
#define GUARD_LOWER_TIME 0.3
#define PUSHER_OUT_TIME 0.5
#define PUSHER_BACK_TIME 0.3
#define SPEED_TIMEOUT 3.0

ShootDisk::ShootDisk() {
	AddSequential(new PrintCommand("Waiting!"));
	AddSequential(new WaittoShoot(), SPEED_TIMEOUT);

	AddParallel(new MaintainSpeed());
	AddSequential(new PrintCommand("Go!!"));
	AddSequential(new WaitCommand(DROP_TIME));

	AddSequential(new DropBlocker());
	AddSequential(new WaitCommand(GUARD_LOWER_TIME));
	AddSequential(new MoveKickerForward());
	AddSequential(new WaitCommand(PUSHER_OUT_TIME));
	AddSequential(new RetractKicker());
	AddSequential(new WaitCommand(PUSHER_BACK_TIME));
	AddSequential(new RaiseBlocker());
	AddSequential(new PrintCommand("Done!!!"));
}
