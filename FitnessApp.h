#ifndef SDDS_FITNESSAPP_H
#define SDDS_FITNESSAPP_H

#include <iostream>
#include "Menu.h"
#include "FitMacros.h"

namespace sdds {
	class FitnessApp {
		bool m_changed{};
		Menu m_mainMenu{};
		Menu m_exitMenu{};
		Menu m_workOutsMenu{};
		char m_fileNme[SDDS_FILE_NAME_LEN + 1]{};
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
