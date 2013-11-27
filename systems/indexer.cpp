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
#define REVERSE_MOTOR (1)

void Indexer::Spin(float speed) {
	setpoint = speed;
	indexerWheel->Set(REVERSE_MOTOR * speed);
}
double Indexer::DebugSpeed() {
	return indexerWheel->GetOutputVoltage();
}
double Indexer::DebugCurrent() {
	return indexerWheel->GetOutputCurrent();
}
double Indexer::DebugSetPoint() {
	return setpoint;
}
