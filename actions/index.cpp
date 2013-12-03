#include "../actions/index.h"
#include "../robot.h"

// Index Manual

IndexManual::IndexManual() :
		CommandStub("Index Manual") {
	Requires(Robot::indexer);
}
void IndexManual::Execute() {
	Robot::indexer->Spin(Robot::oi->getIndexManualPower());
}

// Index Cycle

IndexCycle::IndexCycle() :
		CommandGroup("Index Cycle") {
	AddSequential(new IndexFull());
	AddSequential(new IndexIn());
}

// Index Full

IndexFull::IndexFull() :
		CommandStub("Index Full") {
	Requires(Robot::indexer);
}
void IndexFull::Execute() {
	Robot::indexer->Spin(0.0);
}
bool IndexFull::IsFinished() {
	return !Robot::shooter->holdsDisk();
}

// Index In

IndexIn::IndexIn() :
		CommandStub("Index In") {
	Requires(Robot::indexer);
}
void IndexIn::Execute() {
	Robot::indexer->Spin(0.3);
}
bool IndexIn::IsFinished() {
	return Robot::shooter->holdsDisk();
}
