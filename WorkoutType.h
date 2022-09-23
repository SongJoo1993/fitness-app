#ifndef SDDS_WORKOUTTYPE_H
#define SDDS_WORKOUTTYPE_H

#include "Workout.h"
#include "Weight.h"
#include "Date.h"

namespace sdds {

	class WorkoutType: public Workout {
		char* w_name{};
		Date w_date{};
	public:
		WorkoutType(const char* name = nullptr);
		void resetDate();
		Date checkoutDate()const;

		virtual std::ostream& write(std::ostream&)const = 0;
		virtual std::istream& read(std::istream&) = 0;
		virtual operator bool() const = 0;
		virtual bool conIO(std::ios&)const;
		virtual ~WorkoutType();
	};
}
#endif
