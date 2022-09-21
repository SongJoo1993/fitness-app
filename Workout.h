#ifndef SDDS_WORKOUT_H
#define SDDS_WORKOUT_H

namespace sdds {

	class Workout {
	public: 
		virtual std::ostream& write(std::ostream&)const = 0;
		virtual std::istream& read(std::istream&) = 0;
		virtual bool conIO(std::ios&)const = 0;
		virtual operator bool() const = 0;
		virtual ~Workout() {};
	};
	std::ostream& operator<<(std::ostream& output, const Workout& rop);
	std::istream& operator>>(std::istream& input, Workout& rop);
}
#endif
