#ifndef INDEXER_H
#define INDEXER_H

#include "WPILib.h"

class Indexer: public Subsystem {
private:
	double setpoint;
	CANJaguar* indexerWheel;
public:
	Indexer();
	void InitDefaultCommand();
	
	void Spin(float speed);
	
	double DebugSpeed();
	double DebugCurrent();
	double DebugSetPoint();
};
#endif
