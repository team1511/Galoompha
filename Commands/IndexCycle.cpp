#include "IndexCycle.h"
#include "IndexFull.h"
#include "IndexIn.h"

IndexCycle::IndexCycle() {
	AddSequential(new IndexFull());
	AddSequential(new IndexIn());
}
