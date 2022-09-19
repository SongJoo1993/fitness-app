#include <iostream>
#include <string>
#include "Utils.h"
#include "FitnessApp.h"
using namespace std;

namespace sdds {
	//Private members
	bool FitnessApp::confirm(const char* message)
	{
		bool result{};
		unsigned selection{};
		Menu newMenu(message);
		newMenu << "Yes";
		selection = newMenu.run();
		selection == 1 ? result = true : result = false;
		return result;
	}

	void FitnessApp::load(const char*)
	{
	}

	//Public members
	FitnessApp::FitnessApp(const char* fName)
	{
		m_changed = false;
		ut.strcpy(m_fileNme, fName);
		m_workOutsMenu.setTitle("Choose the type of Work-Out:");
		m_workOutsMenu << "Weight" << "Cardio";
		m_mainMenu.setTitle("Song's Fitness App");
		m_mainMenu << "Add New Work-out Records"
			<< "Track Previous Workout Records";
		m_exitMenu.setTitle("Changes have been made to the data, what would you like to do?");
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
	}

	void FitnessApp::run() const
	{
		bool done{};
		unsigned selection{};

		do
		{
			selection = m_mainMenu.run();
			switch (selection)
			{
			case 0:
				done = true;
				break;
			case 1:
				newWorkout();
				std::cout << std::endl;
				break;
			case 2:
				trackWorkout();
				std::cout << std::endl;
				break;
			default:
				break;
			}

			if (m_changed && done == true) {
				selection = m_exitMenu.run();
				if (selection == 1) {
					save();
				}
				else if (selection == 2) {
					std::cout << std::endl;
					done = false;
				}
				else if (selection == 0) {
					selection = confirm("This will discard all the changes are you sure?");
					if (selection) {
						done = true;
					}
					else {
						done = false;
					}
				}
			}
			else if (!m_changed && done == true) {
				done = true;
			}
			else {
				done = false;
			}

		} while (!done);

		std::cout << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "Thanks for using Seneca Library Application" << std::endl;
	}

}