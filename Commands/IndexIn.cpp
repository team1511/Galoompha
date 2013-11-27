#include "IndexIn.h"
IndexIn::IndexIn() {
	Requires(Robot::indexer);
}
void IndexIn::Initialize() {
}
void IndexIn::Execute() {
	Robot::indexer->Spin(0.3);
}
bool IndexIn::IsFinished() {
	return Robot::shooter->holdsDisk();
}
void IndexIn::End() {
}
void IndexIn::Interrupted() {
}
