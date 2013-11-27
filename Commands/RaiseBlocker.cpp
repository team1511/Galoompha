#include "RaiseBlocker.h"
RaiseBlocker::RaiseBlocker() {
	Requires(Robot::shooter);
}
void RaiseBlocker::Initialize() {
	
}
void RaiseBlocker::Execute() {
	Robot::shooter->block(true);
}
bool RaiseBlocker::IsFinished() {
	return true;
}
void RaiseBlocker::End() {
	
}
void RaiseBlocker::Interrupted() {
}
