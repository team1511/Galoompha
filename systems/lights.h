#ifndef LIGHTS_H
#define LIGHTS_H

#include "WPILib.h"

class Lights: public Subsystem {
public:
	Lights();
	void InitDefaultCommand();

	typedef enum {kNone, kLifting, kReady} FeedState; 
	void setFeed(FeedState t);
private:
	I2C* chip;
	FeedState state;
};
#endif
