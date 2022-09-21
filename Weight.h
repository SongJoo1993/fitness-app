#ifndef SDDS_WEIGHT_H
#define SDDS_WEIGHT_H

#include "WorkoutType.h"
#include "FitMacros.h"

namespace sdds {

	class Weight: public WorkoutType {
		int w_set[SDDS_WEIGHTSETS_CAPACITY]{};
		int w_reps[SDDS_WEIGHTSETS_CAPACITY]{};
		int w_pounds[SDDS_WEIGHTSETS_CAPACITY]{};
	public:


	};
}
#endif 


