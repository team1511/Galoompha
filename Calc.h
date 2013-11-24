#ifndef __CALC__H_
#define __CALC__H_

double linearRangeScale(double val, double min, double max,
		double newMin, double newMax);

double bound(double val, double min, double max);

double powerJoystickCurve(double axisvalue, bool slow, bool turbo);

#endif
