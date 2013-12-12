#include "lights.h"


Lights::Lights() :
		Subsystem("Lights") {
	chip = DigitalModule::GetInstance(1)->GetI2C(0x41);
	
	if ((chip == NULL) || chip->Write((UINT8) 0x00, (UINT8) 0x00)) {
		printf("ERROR I2C loading Failed\n");
		chip = NULL;
	}
	setFeed(kNone);
	
}
void Lights::InitDefaultCommand() {
	// insert fun disabled mode default command for when the Feed stuff doesn't take it
}

void Lights::setFeed(Lights::FeedState t) {
	if (chip == NULL) return;
	
	if (t != state) {
		state = t;
		uint8_t bank = 0x00;
		switch (state) {
		case kNone:
			break;
		case kReady:
			bank |= 0x01;
			break;
		case kLifting:
			bank |= 0x02;
			break;
		}
		chip->Write(0x09,bank);
	}
}
