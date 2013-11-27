#include "DropBlocker.h"
DropBlocker::DropBlocker() {
	Requires(Robot::shooter);
}
void DropBlocker::Initialize() {
}
void DropBlocker::Execute() {
	Robot::shooter->block(false);
}
bool DropBlocker::IsFinished() {
	return true;
}
void DropBlocker::End() {
}
void DropBlocker::Interrupted() {
}
