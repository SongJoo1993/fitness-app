#ifndef SDDS_FITNESSAPP_H
#define SDDS_FITNESSAPP_H

#include <iostream>
#include "Menu.h"
#include "FitMacros.h"
#include "WorkoutType.h"

namespace sdds {
	class FitnessApp {
		bool f_changed{};
		Menu f_mainMenu{};
		Menu f_exitMenu{};
		Menu f_workOutsMenu{};
		char f_fileNme[SDDS_FILE_NAME_LEN + 1]{};
		WorkoutType* f_workouts[SDDS_RECORDS_CAPACITY]{};
		int f_numOfWorkOuts{};
		bool confirm(const char* message);
		void load(const char*);
		void save();
		void newWorkout();
		void trackWorkout();
		void displayPubs();
	public:
		FitnessApp(const char*);
		void run();
		~FitnessApp();
	};
}
#endif
