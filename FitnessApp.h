#ifndef SDDS_FITNESSAPP_H
#define SDDS_FITNESSAPP_H

namespace sdds {
	class FitnessApp {
		bool m_changed{};
	public:
		unsigned selection();
		void displayItems() const;
		void run() const;
		void newWorkout();
		void trackWorkout();
	};
}
#endif
