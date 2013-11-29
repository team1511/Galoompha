#include "SmartDashboard/SmartDashboard.h"

#include "controls.h"
#include "utils/calc.h"

#include "actions/autonomous.h"
#include "actions/drive_tank.h"
#include "actions/index.h"
#include "actions/lift.h"
#include "actions/shoot.h"
#include "actions/debug.h"
#include "actions/climb.h"

void addSD(Command* c) {
	SmartDashboard::PutData(c->GetName(), c);
}

class ChangeCommand: public OneShotCommand {
private:
	bool vv;
public:
	ChangeCommand(bool val) :
			OneShotCommand("Control change") {
		SetRunWhenDisabled(true);
		vv = val;
	}
	virtual void Call(bool newval) = 0;
protected:
	virtual void Execute() {
		Call(vv);
	}
};

// yes, could implement this via Trigger etc.
class SetEncoder: public ChangeCommand {
	virtual void Call(bool newval) {
		Robot::shooterWheel->setEncoderBroken(newval);
	}
};

// this is better than a trigger; its state does not persist between modes,
// as it is wiped through Scheduler::removeAll()
class DoAfterDeploy: public OneShotCommand {
public:
	DoAfterDeploy(Command* c) :
			OneShotCommand("Run Mystery Command After Deploy") {
		todo = c;
	}
	virtual void Initialize() {
		if (Robot::deployer->hasDeployed()) {
			todo->Start();
		}
	}
private:
	Command* todo;
};

OI::OI() {
	// Process operator interface input here.

	virtualStick = new Joystick(4);
	indexBroken = new JoystickButton(virtualStick, 1);
	indexBroken->WhileHeld(new IndexManual());
	angleBroken = new JoystickButton(virtualStick, 3);
	angleBroken->WhileHeld(new LiftManual());
	coastMode = new JoystickButton(virtualStick, 5);
	coastMode->WhileHeld(new TankDrive(Drive::kCoast));
	wheelEncBroken = new JoystickButton(virtualStick, 2);
	wheelEncBroken->WhenPressed(new SetEncoder(true));
	wheelEncBroken->WhenReleased(new SetEncoder(false));

	auxStick = new Joystick(3);
	shoot = new JoystickButton(auxStick, 1);
	shoot->WhileHeld(new ShootDisk());
	feed = new JoystickButton(auxStick, 2);
	feed->WhileHeld(new LiftFeed());
	climbOverride = new JoystickButton(auxStick, 10);
	climbOverride->WhileHeld(new ArmsManual());

	dump1 = new JoystickButton(auxStick, 11);
	dump2 = new JoystickButton(rightDrive, 11);
	dump1->WhenPressed(new DoAfterDeploy(new Dump()));
	dump2->WhenPressed(new DoAfterDeploy(new Dump()));
	deploy = new JoystickButton(auxStick, 10);
	deploy->WhenPressed(new DeploySequence());

	rightDrive = new Joystick(2);

	leftDrive = new Joystick(1);
	driveDebug = new JoystickButton(leftDrive, 11);
	driveDebug->WhileHeld(new DebugDrive());
	shooterDebug = new JoystickButton(leftDrive, 6);
	shooterDebug->WhileHeld(new DebugShooter());
	climberDebug = new JoystickButton(leftDrive, 7);
	climberDebug->WhileHeld(new DebugClimber());

	// SmartDashboard Buttons
	addSD(new AutonRoutine());

	addSD(new LiftFeed());
	addSD(new LiftStatic());
	addSD(new LiftManual());

	addSD(new IndexIn());
	addSD(new IndexCycle());
	addSD(new IndexManual());
	addSD(new IndexFull());

	addSD(new TankDrive(Drive::kBrake));
	addSD(new TankDrive(Drive::kCoast));

	addSD(new DebugNothing());
	addSD(new DebugClimber());
	addSD(new DebugShooter());
	addSD(new DebugDrive());

	addSD(new ShootDisk());
	addSD(new MoveBlocker(MoveBlocker::kClear));
	addSD(new MoveBlocker(MoveBlocker::kBlock));
	addSD(new MoveKicker(MoveKicker::kKick));
	addSD(new MoveKicker(MoveKicker::kRetract));
	addSD(new WaittoShoot());
	addSD(new MaintainSpeed());
	addSD(new ShooterIdle());

	addSD(new DeploySequence());
	addSD(new ArmsManual());
	addSD(new Dump());
	addSD(new DoAfterDeploy(new Dump()));
	addSD(new Deploy());
	addSD(new LockShooter());
	addSD(new LockLift());
	addSD(new LockIndexer());
}

double getDrivePower(Joystick* stick) {
	double input = stick->GetY();
	bool slow = stick->GetRawButton(1);
	bool turbo = stick->GetRawButton(2);
	return powerJoystickCurve(input, slow, turbo);
}

double OI::getLeftDrivePower() {
	return getDrivePower(leftDrive);
}

double OI::getRightDrivePower() {
	return getDrivePower(rightDrive);
}

double OI::getSpeedSliderValue() {
	float slider = virtualStick->GetX();
	float speed = linearRangeScale(slider, -1.0f, 1.0f, 0.3f, 1.0f);
	return speed;
}

double OI::getAngleSliderValue() {
	double pre = -1 * virtualStick->GetY();
	return pre;
}

double OI::getIndexManualPower() {
	return auxStick->GetX(GenericHID::kRightHand);
}

double OI::getClimberPower() {
	return -1 * auxStick->GetY();
}

bool OI::getClimberLimitsBroken() {
	return virtualStick->GetRawButton(6);
}

bool OI::getContinuousShooting() {
	return virtualStick->GetRawButton(8);
}

