#ifndef MONOENCODER_H
#define MONOENCODER_H

#include "Counter.h"
#include "PIDSource.h"
#include "LiveWindow/LiveWindowSendable.h"

#define TICKS_PER_REV   250

// Extends counter to be treated as an encoder
class MonoEncoder: public PIDSource, LiveWindowSendable {
public:
	MonoEncoder(int channel, double max_rps, int ticks_per_revolution);
	virtual ~MonoEncoder();
	virtual double PIDGet();
	double getSpeed();// as percentage (%) of max rps
	int getCount();// in ticks
	void Restart();
	double getRPS();// revs per second
	double getRPM();// revs per minute

	void UpdateTable();
	void StartLiveWindowMode();
	void StopLiveWindowMode();
	virtual std::string GetSmartDashboardType();
	void InitTable(ITable *subTable);
	ITable * GetTable();
private:
	int ticks_per_rev;
	Counter * count;
	ITable* table;
	double lastSpeed;
	double maxRPS;
};

#endif //MONOENCODER_H
