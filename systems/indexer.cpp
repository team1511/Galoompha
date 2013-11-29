#include "systems/indexer.h"
#include "robotmap.h"
#include "actions/index.h"

Indexer::Indexer() : Subsystem("Indexer") {
	indexerWheel = RobotMap::indexerIndexerWheel;
	setpoint = 0.0;
}
    
void Indexer::InitDefaultCommand() {
	SetDefaultCommand(new IndexCycle());
}

void Indexer::Spin(double speed) {
	setpoint = speed;
	indexerWheel->Set(speed);
}

double Indexer::getCurrent() {
	return indexerWheel->GetOutputCurrent();
}
double Indexer::getSpeed() {
	return setpoint;
}
