#ifndef UTILS_RESETTABLE_SUBSYSTEM_H_
#define UTILS_RESETTABLE_SUBSYSTEM_H_

#include "Commands/Subsystem.h"
#include <set>

class ResettableSubsystem : public Subsystem {
public:
	ResettableSubsystem(const char* name);
	virtual void Reset();

	static void ResetAll();
private:
	static std::set<ResettableSubsystem*>* systems;
};

#endif // UTILS_RESETTABLE_SUBSYSTEM_H_
