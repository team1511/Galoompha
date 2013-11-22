#include "Calc.h"

double linearRangeScale(double v, double min, double max,
		double newMin, double newMax) {
	double oldr = (max - min);
	double newr = (newMax - newMin);
	return (((v - min) * newr) / oldr) + newMin;
}

double bound(double val, double min, double max) {
	if (val < min) {
		return min;
	}
	if (val > max) {
		return max;
	}
	return val;
}
