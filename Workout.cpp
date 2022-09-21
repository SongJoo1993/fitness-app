#include <iostream>
#include "Workout.h"
using namespace std;

namespace sdds {
	std::ostream& operator<<(std::ostream& output, const Workout& rop)
	{
		if (rop) {
			rop.write(output);
		}
		return output;
	}

	std::istream& operator>>(std::istream& input, Workout& rop)
	{
		return rop.read(input);
	}

}