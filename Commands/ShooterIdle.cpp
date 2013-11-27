#include "ShooterIdle.h"
ShooterIdle::ShooterIdle() {
	Requires(Robot::shooterWheel);
}
void ShooterIdle::Initialize() {
	
}
void ShooterIdle::Execute() {
	Robot::shooterWheel->setTargetSpeed(0.0);
}
bool ShooterIdle::IsFinished() {
	return false;
}
void ShooterIdle::End() {
	
}
void ShooterIdle::Interrupted() {
}
