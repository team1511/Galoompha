#include "../actions/dashboard.h"
#include "../robot.h"

UpdateDashboard::UpdateDashboard() :
	CommandStub("Update Dashboard") {
	Requires(Robot::dashboard);
	SetRunWhenDisabled(true);
}
void UpdateDashboard::Execute() {
	SmartDashboard::PutNumber("Shooterpower", Robot::oi->getSpeedSliderValue() * 100);
	if (Robot::getInstance().IsEnabled()) {
		SmartDashboard::PutNumber("Desiredangle", Robot::anglingTool->getTarget() * 100);
	} else {
		SmartDashboard::PutNumber("Desiredangle", Robot::oi->getAngleSliderValue() * 100);
	}
	SmartDashboard::PutNumber("Actualangle", Robot::anglingTool->getAngle() * 100);
}
