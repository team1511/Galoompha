#include "../utils/calc.h"

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

double powerJoystickCurve(double axisvalue, bool slow, bool turbo) {
	double power;

	//Deadzone, prevents motors from running
	//when not touching the joysticks
	if (axisvalue > -.05 && axisvalue < .05) {
		power = 0;
	} else {
		power = axisvalue * axisvalue * axisvalue;
		if (slow) {
			power *= 0.3;
		} else if (!turbo) {
			power *= 0.7;
		}
	}
	return power;
}
