#ifndef UTILS_SENDABLE_COMMAND_CHOOSER_H_
#define UTILS_SENDABLE_COMMAND_CHOOSER_H_

#include "SmartDashboard/SendableChooser.h"
#include "Commands/Command.h"

class SendableCommandChooser {
public:
	explicit SendableCommandChooser(const char* name);
	virtual ~SendableCommandChooser();
	void AddDefault(Command* comm);
	void AddCommand(Command* comm);
	Command* GetSelected();
private:
	SendableChooser chooser;
};

#endif // UTILS_SENDABLE_COMMAND_CHOOSER_H_
