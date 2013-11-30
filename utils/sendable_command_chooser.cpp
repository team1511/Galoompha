#include "utils/sendable_command_chooser.h"
#include "SmartDashboard/SmartDashboard.h"

SendableCommandChooser::SendableCommandChooser(const char* name) :
		chooser() {
	SmartDashboard::PutData(name, &chooser);
}
SendableCommandChooser::~SendableCommandChooser() {
}
void SendableCommandChooser::AddDefault(Command* comm) {
	chooser.AddDefault(comm->GetName().c_char(), comm);
}
void SendableCommandChooser::AddCommand(Command* comm) {
	chooser.AddObject(comm->GetName().c_char(), comm);
}
Command* SendableCommandChooser::GetSelected() {
	return chooser.GetSelected();
}

