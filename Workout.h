#ifndef SDDS_WORKOUT_H
#define SDDS_WORKOUT_H

namespace sdds {

	class Workout {
	public:
		virtual std::istream& write(std::istream&) = 0;
		virtual std::ostream& read(std::ostream&) = 0;
		virtual ~Workout() {};
	};
}
#endif
