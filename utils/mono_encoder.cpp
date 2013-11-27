#include "utils/mono_encoder.h"

MonoEncoder::MonoEncoder(int channel, double max_rps, int tpr) {
	ticks_per_rev = tpr;
	maxRPS = max_rps;

	count = new Counter(channel);
	count->SetSamplesToAverage(127);
	count->Start();

	table = 0;
}

MonoEncoder::~MonoEncoder() {
	delete count;
}

void MonoEncoder::Restart() {
	count->Reset();
	count->Start();
}

int MonoEncoder::getCount() {
	return count->Get();
}

double MonoEncoder::getSpeed() {
	double period = count->GetPeriod();
	return 1 / (period * ticks_per_rev * maxRPS);
}

double MonoEncoder::getRPS() {
	return getSpeed() * maxRPS;
}

double MonoEncoder::getRPM() {
	return getSpeed() * maxRPS * 60.0;
}

double MonoEncoder::PIDGet() {
	return getSpeed();
}


// we mimic Encoder
void MonoEncoder::UpdateTable() {
	if (table) {
		table->PutNumber("Speed", getSpeed());
		table->PutNumber("Distance", getCount());
		table->PutNumber("Distance per Tick", 1.0);
	}
}

void MonoEncoder::StartLiveWindowMode() {
}

void MonoEncoder::StopLiveWindowMode() {
}

std::string MonoEncoder::GetSmartDashboardType() {
	return "Encoder";
}

void MonoEncoder::InitTable(ITable *subTable) {
	table = subTable;
	UpdateTable();
}

ITable * MonoEncoder::GetTable() {
	return table;
}



