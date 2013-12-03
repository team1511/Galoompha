#include "../actions/shoot.h"
#include "../utils/calc.h"
#include "../robot.h"
#include "../utils/unbind_subsystem.h"

const double DROP_TIME = 0.5;
const double GUARD_LOWER_TIME = 0.3;
const double PUSHER_OUT_TIME = 0.5;
const double PUSHER_BACK_TIME = 0.3;
const double SPEED_TIMEOUT = 3.0;

ShootDisk::ShootDisk(ShooterWheel::SpeedSource v, double speed) :
		CommandGroup("Shoot Disk") {
	AddParallel(new MaintainSpeed(v, speed));
	// main block
	AddSequential(new WaitUntilReadyToShoot(), SPEED_TIMEOUT);
	AddSequential(new WaitCommand(DROP_TIME));
	AddSequential(new MoveBlocker(MoveBlocker::kClear));
	AddSequential(new WaitCommand(GUARD_LOWER_TIME));
	AddSequential(new MoveKicker(MoveKicker::kKick));
	AddSequential(new WaitCommand(PUSHER_OUT_TIME));
	AddSequential(new MoveKicker(MoveKicker::kRetract));
	AddSequential(new WaitCommand(PUSHER_BACK_TIME));
	AddSequential(new MoveBlocker(MoveBlocker::kBlock));
	// terminates the MaintainSpeed
	AddSequential(new UnbindSubsystem(Robot::shooterWheel));
}

// Move Kicker

MoveKicker::MoveKicker(Direction d) :
		OneShotCommand((d == kKick) ? "Kicker: Kick" : "Kicker: Retract") {
	dir = d;
}
void MoveKicker::Execute() {
	Robot::shooter->kick((dir == kKick));
}

// Move Blocker

MoveBlocker::MoveBlocker(Position p) :
		OneShotCommand((pos == kBlock) ? "Blocker: Block" : "Blocker: Clear") {
	pos = p;
}
void MoveBlocker::Execute() {
	Robot::shooter->block((pos == kBlock));
}

// Shooter Idle

ShooterIdle::ShooterIdle() :
		CommandStub("Shooter Idle") {
	Requires(Robot::shooterWheel);
}
void ShooterIdle::Execute() {
	if (Robot::oi->getContinuousShooting()) {
		Robot::shooterWheel->setTargetSpeed(Robot::oi->getSpeedSliderValue());
	} else {
		Robot::shooterWheel->setTargetSpeed(0.0);
	}
}

// Maintain Speed

MaintainSpeed::MaintainSpeed(ShooterWheel::SpeedSource v, double speed) :
		CommandStub("Maintain Speed") {
	Requires(Robot::shooterWheel);
	mode = v;
	target = speed;
}
void MaintainSpeed::Execute() {
	double speed;
	if (mode == ShooterWheel::kControls) {
		speed = Robot::oi->getSpeedSliderValue();
	} else {
		speed = target;
	}
	Robot::shooterWheel->setTargetSpeed(speed);
}

// Wait to Shoot

WaittoShoot::WaittoShoot() :
		CommandGroup("Wait To Shoot") {
	AddParallel(new MaintainSpeed());
	AddSequential(new WaitUntilReadyToShoot());
	AddSequential(new UnbindSubsystem(Robot::shooterWheel));
	// set comment on
}

// Wait Until Ready To Shoot

WaitUntilReadyToShoot::WaitUntilReadyToShoot() :
		CommandStub("Wait Until Ready To Shoot") {
}
bool WaitUntilReadyToShoot::IsFinished() {
	return Robot::shooterWheel->atTargetSpeed() && Robot::shooter->holdsDisk();
}

