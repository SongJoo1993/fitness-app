#include <iostream>
#include "WorkoutType.h"
using namespace std;

namespace sdds {
	void WorkoutType::resetDate()
	{
		Date temp{};
		w_date = temp;
	}

	Date WorkoutType::checkoutDate() const
	{
		return w_date;
	}

	bool WorkoutType::conIO(std::ios& ios) const
	{
		return &ios == &std::cout || &ios == &std::cin;
	}

	WorkoutType::~WorkoutType()
	{
		delete[] w_name;
	}

}