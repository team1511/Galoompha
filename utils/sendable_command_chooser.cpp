#include "../utils/sendable_command_chooser.h"
#include "SmartDashboard/SmartDashboard.h"
#include <string>

SendableCommandChooser::SendableCommandChooser(const char* name) :
		chooser() {
	SmartDashboard::PutData(name, &chooser);
}
SendableCommandChooser::~SendableCommandChooser() {
}
void SendableCommandChooser::AddDefault(Command* comm) {
	chooser.AddDefault(comm->GetName().data(), comm);
}
void SendableCommandChooser::AddCommand(Command* comm) {
	chooser.AddObject(comm->GetName().data(), comm);
}
Command* SendableCommandChooser::GetSelected() {
	return (Command*)chooser.GetSelected();
}

