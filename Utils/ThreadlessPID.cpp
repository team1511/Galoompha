#include "ThreadlessPID.h"

ThreadlessPID::ThreadlessPID(double p, double i, double d, double f) {
	setConstants(p,i,d,f);
	integral = 0.0;
	lerror = 0.0;
	ltime = GetTime();
}

void ThreadlessPID::setConstants(double p, double i, double d, double f) {
	k_p = p;
	k_i = i;
	k_d = d;
	k_f = f;
}

void ThreadlessPID::reset() {
	integral = 0.0;
	lerror = 0.0;
	ltime = GetTime();
}

double ThreadlessPID::calc(double target, double measure) {
	double time_new = GetTime();
	double tdelta = time_new - ltime;
	ltime = time_new;

	double error_new = target - measure;
	double diff = (error_new - lerror) / tdelta;
	lerror = error_new;

	integral += error_new * tdelta;

	return (k_p * error_new) + (k_d * diff) + (k_i * integral) + (k_f*target);
}

