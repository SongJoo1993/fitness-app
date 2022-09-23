#include <iostream>
#include <fstream>
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

	void FitnessApp::load(const char* fileName)
	{
		std::ifstream fin(fileName);
		while (fin)
		{
			
		}
	}

	void FitnessApp::save()
	{

	}

	void FitnessApp::newWorkout()
	{

	}

	void FitnessApp::trackWorkout()
	{

	}

	void FitnessApp::displayPubs()
	{

	}

	//Public members
	FitnessApp::FitnessApp(const char* fName)
	{
		f_changed = false;
		ut.strcpy(f_fileNme, fName);
		f_workOutsMenu.setTitle("Choose the type of Work-Out:");
		f_workOutsMenu << "Weight" << "Cardio";
		f_mainMenu.setTitle("Song's Fitness App");
		f_mainMenu << "Add New Work-out Records"
			<< "Track Previous Workout Records";
		f_exitMenu.setTitle("Changes have been made to the data, what would you like to do?");
		f_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		load(fName);
	}

	void FitnessApp::run()
	{
		bool done{};
		unsigned selection{};

		do
		{
			selection = f_mainMenu.run();
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

			if (f_changed && done == true) {
				selection = f_exitMenu.run();
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
			else if (!f_changed && done == true) {
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

	FitnessApp::~FitnessApp()
	{
	}

}