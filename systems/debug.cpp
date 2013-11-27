#include "systems/debug.h"
#include "actions/debug.h"

Debug* instance;

Debug::Debug() :
		Subsystem("Debug") {
}
void Debug::InitDefaultCommand() {
	SetDefaultCommand(new DebugNothing());
}

DebugWriter::DebugWriter() {
	lcd = DriverStationLCD::GetInstance();
}

void DebugWriter::clear() {
	lcd->Clear();
}

DebugWriter::~DebugWriter() {
	lcd->UpdateLCD();
}

void DebugWriter::line1(const char* format, ...) {
	va_list args;
	va_start (args, format);
	lcd->VPrintfLine(DriverStationLCD::kUser_Line1, format, args);
	va_end (args);
}
void DebugWriter::line2(const char* format, ...) {
	va_list args;
	va_start (args, format);
	lcd->VPrintfLine(DriverStationLCD::kUser_Line2, format, args);
	va_end (args);
}
void DebugWriter::line3(const char* format, ...) {
	va_list args;
	va_start (args, format);
	lcd->VPrintfLine(DriverStationLCD::kUser_Line3, format, args);
	va_end (args);
}
void DebugWriter::line4(const char* format, ...) {
	va_list args;
	va_start (args, format);
	lcd->VPrintfLine(DriverStationLCD::kUser_Line4, format, args);
	va_end (args);
}
void DebugWriter::line5(const char* format, ...) {
	va_list args;
	va_start (args, format);
	lcd->VPrintfLine(DriverStationLCD::kUser_Line5, format, args);
	va_end (args);
}
void DebugWriter::line6(const char* format, ...) {
	va_list args;
	va_start (args, format);
	lcd->VPrintfLine(DriverStationLCD::kUser_Line6, format, args);
	va_end (args);
}
