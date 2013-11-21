#ifndef MONOENCODER_H
#define MONOENCODER_H

#include "Counter.h"
#include "Timer.h"
#include "PIDSource.h"

#define TICKS_PER_REV   250

// Extends counter to be treated as an encoder
class MonoEncoder: public PIDSource {
public:
	MonoEncoder(int channel, double max_rps, int ticks_per_revolution);
	virtual ~MonoEncoder();
	virtual double PIDGet();
	double getLastSpeed();// as percentage (%) of max rps
	int getTotalCount();// in ticks
	double getRevPerSec();// revs per second
private:
	int ticks_per_rev;
	Counter * count;
	double lastSpeed;
	double maxRPS;
	int totalCount;
};

#endif //MONOENCODER_H
