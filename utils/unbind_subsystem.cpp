#include "utils/unbind_subsystem.h"

UnbindSubsystem::UnbindSubsystem(Subsystem* s) :
		OneShotCommand("Unbind Subsystem") {
	Requires(s);
}

