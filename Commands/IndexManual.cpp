
#include "IndexManual.h"
IndexManual::IndexManual() {
	Requires(Robot::indexer);
}
void IndexManual::Initialize() {
	
}
void IndexManual::Execute() {
	Robot::indexer->Spin(Robot::oi->getIndexManualPower());
}
bool IndexManual::IsFinished() {
	return false;
}
void IndexManual::End() {
	
}
void IndexManual::Interrupted() {
}
