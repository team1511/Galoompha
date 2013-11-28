#ifndef UTILS_RESETTABLE_SUBSYSTEM
#define UTILS_RESETTABLE_SUBSYSTEM

#include "Commands/Subsystem.h"
#include <set>

class ResettableSubsystem : public Subsystem {
public:
	ResettableSubsystem(const char* name);
	virtual void Reset();

	static void ResetAll();
private:
	static std::set<ResettableSubsystem*> systems;
};

#endif // UTILS_RESETTABLE_SUBSYSTEM
