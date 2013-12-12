#include "../actions/dashboard.h"
#include "../robot.h"

const std::string SD_ANGLE_TARGET = "Desiredangle";
const std::string SD_ANGLE_ACTUAL = "Actualangle";

UpdateDashboard::UpdateDashboard() :
	CommandStub("Update Dashboard") {
	Requires(Robot::dashboard);
	SetRunWhenDisabled(true);
}
void UpdateDashboard::Execute() {
	SmartDashboard::PutNumber("Shooterpower", Robot::oi->getSpeedSliderValue() * 100);
}
