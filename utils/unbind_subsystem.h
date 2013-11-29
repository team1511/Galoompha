#ifndef UTILS_UNBIND_SUBSYSTEM_H_
#define UTILS_UNBIND_SUBSYSTEM_H_

#include "utils/command_stub.h"

class UnbindSubsystem : OneShotCommand {
public:
	UnbindSubsystem(Subsystem* s);
};

#endif //UTILS_UNBIND_SUBSYSTEM_H_
