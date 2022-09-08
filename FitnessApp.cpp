#include <iostream>
#include <string>
#include "Utils.h"
#include "FitnessApp.h"
using namespace std;

namespace sdds {
	unsigned FitnessApp::selection()
	{
		unsigned selectNo{};
		displayItems();
		selectNo = ut.validSelection(m_itemNo);
		return selectNo;
	}
	
	void FitnessApp::displayItems() const
	{

	}

	void FitnessApp::newWorkout()
	{
		std::cout << "Adding New";
	}

	void FitnessApp::trackWorkout()
	{
		std::cout << "Track Past Records";
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
		displayPubs();
	}
}