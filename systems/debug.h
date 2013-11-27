#ifndef SYSTEMS_DEBUG_H_
#define SYSTEMS_DEBUG_H_

#include "WPILib.h"

class Debug: public Subsystem {
	Debug();
	void InitDefaultCommand();
};

class DebugWriter {
public:
	DebugWriter();
	~DebugWriter();

	void clear();

	void line1(const char* format, ...);
	void line2(const char* format, ...);
	void line3(const char* format, ...);
	void line4(const char* format, ...);
	void line5(const char* format, ...);
	void line6(const char* format, ...);
private:
	DriverStationLCD* lcd;
};

#endif // SYSTEMS_DEBUG_H_
