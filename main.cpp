/* 
App Description: Allowing the user to track fitness achievement!
*/

#include <iostream>
#include "FitnessApp.h"

int main() {
	sdds::FitnessApp fApp("WorkoutRecs.txt");
	fApp.run();
	return 0;
}