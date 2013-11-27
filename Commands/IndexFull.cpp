#include "IndexFull.h"
IndexFull::IndexFull() {
	Requires(Robot::indexer);
}
void IndexFull::Initialize() {
}
void IndexFull::Execute() {
	Robot::indexer->Spin(0.0);
}
bool IndexFull::IsFinished() {
	return !Robot::shooter->holdsDisk();
}
void IndexFull::End() {
}
void IndexFull::Interrupted() {
}
