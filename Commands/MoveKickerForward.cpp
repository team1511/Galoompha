#include "MoveKickerForward.h"
MoveKickerForward::MoveKickerForward() {
	Requires(Robot::shooter);
}
void MoveKickerForward::Initialize() {
	
}
void MoveKickerForward::Execute() {
	Robot::shooter->kick(true);
}
bool MoveKickerForward::IsFinished() {
	return true;
}
void MoveKickerForward::End() {
	
}
void MoveKickerForward::Interrupted() {
}
