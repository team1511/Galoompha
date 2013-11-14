#include "Calc.h"

float linearRangeScale(float v, float min, float max,
		float newMin, float newMax) {
	float oldr = (max - min);
	float newr = (newMax - newMin);
	return (((v - min) * newr) / oldr) + newMin;
}
