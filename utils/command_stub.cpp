#include "../utils/command_stub.h"

CommandStub::CommandStub(const char* name) :
		Command(name) {
}
CommandStub::CommandStub(const char* name, double timeout) :
		Command(name, timeout) {
}

/**
 * Default: no action
 */
void CommandStub::Initialize() {
}
/**
 * Default: no action
 */
void CommandStub::Execute() {
}
/**
 * Default: never finishes
 */
bool CommandStub::IsFinished() {
	return false;
}
/**
 * Default: no action
 */
void CommandStub::End() {
}
/**
 * Default: calls CommandStub::end()
 */
void CommandStub::Interrupted() {
	End();
}

OneShotCommand::OneShotCommand(const char* f) :
		CommandStub(f) {
}
bool OneShotCommand::IsFinished() {
	return true;
}
