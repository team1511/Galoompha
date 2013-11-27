#include "RetractKicker.h"
RetractKicker::RetractKicker() {
	Requires(Robot::shooter);
}
void RetractKicker::Initialize() {

}
void RetractKicker::Execute() {
	Robot::shooter->kick(false);
}
bool RetractKicker::IsFinished() {
	return true;
}
void RetractKicker::End() {

}
void RetractKicker::Interrupted() {
}
