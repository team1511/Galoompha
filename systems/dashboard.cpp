#include "../systems/dashboard.h"
#include "../actions/dashboard.h"

DashBoard::DashBoard() : Subsystem("Dashboard") {
}
void DashBoard::InitDefaultCommand() {
	SetDefaultCommand(new UpdateDashboard());
}
