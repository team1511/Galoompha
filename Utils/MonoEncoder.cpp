#include "MonoEncoder.h"

MonoEncoder::MonoEncoder(int channel, double max_rps, int tpr) {
	count = new Counter(channel);
	count->SetSamplesToAverage(127);
	ticks_per_rev = tpr;
	count->Start();
	totalCount = 0;
	lastSpeed = 0;
	maxRPS = max_rps;
}

MonoEncoder::~MonoEncoder() {
	delete count;
}

int MonoEncoder::getTotalCount() {
	return count->Get();
}

double MonoEncoder::getLastSpeed() {
	return lastSpeed;
}

double MonoEncoder::getRevPerSec() {
	return lastSpeed * maxRPS;
}

double MonoEncoder::PIDGet() {
	double period = count->GetPeriod();
	lastSpeed = 1 / (period * ticks_per_rev * maxRPS);
	return lastSpeed;
}
