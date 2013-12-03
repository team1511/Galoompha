#include "../utils/resettable_subsystem.h"

std::set<ResettableSubsystem*>* ResettableSubsystem::systems = 0;

ResettableSubsystem::ResettableSubsystem(const char* name) :
		Subsystem(name) {
	if (systems == 0) {
		systems = new std::set<ResettableSubsystem*>();
	}
	systems->insert(this);
}

void ResettableSubsystem::Reset() {

}

void ResettableSubsystem::ResetAll() {
	if (systems == 0)
		return;
	std::set<ResettableSubsystem*>::iterator subsystemIter = systems->begin();
	for (; subsystemIter != systems->end(); subsystemIter++) {
		ResettableSubsystem *sys = *subsystemIter;
		sys->Reset();
	}
}

