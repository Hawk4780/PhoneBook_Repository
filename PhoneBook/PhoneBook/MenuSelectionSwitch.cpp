#include"MenuSelectionSwitch.h"

/**
* @file MenuSelectionSwitch.cpp
* @brief This contains functions and variable regarding menu selection
*/

bool Exit = false;/**<A global varibale to check whethere user wants to exit from the program*/

				  /**
				  * @enum Selection to show main menu options.
				  */
enum Selection
{
	displayContacts = 1, /**< enum vlaue 1*/
	searchContacts,/**< enum value 2*/
	addContacts,/**< enum value 3*/
	deletContacts,/**< enum value 4*/
	Quit/**< enum value 5*/
};

/**
* @brief Function which excutes options according to user choice from main menu.
* This function will validate user input at displays error message,
* When ever user input an invalid input. This will display an error and force him
* to enter a valid input. When valid input is given do things according to user choice.
* @param options which stores user input.
* @return Void
*/
void MenuSelection()
{
	int options;
	std::cin >> options;
	if (options > 5)
	{
		do
		{
			std::cout << "Please enter a valid number" << std::endl;
			std::cin >> options;
		} while (options > 5);
	}
	int MenuOption = options;

	switch (MenuOption)
	{
	case displayContacts:
		DisplayContacts();
		system("pause");
		break;
	case searchContacts:
		SearchContacts();
		break;
	case addContacts:
		AddContacts();
		break;
	case deletContacts:
		DeleteContact();
		break;
	case Quit:
		Exit = true;
		break;
	default:
		break;
	}
}
/**
* @brief Function which checks Exit status.
* When ever user wants to exit bool-Exit will be true and this function checks its status
* @return 1 when Exit is true and 0 when Exit is false.
*/
bool exit()
{
	if (Exit == true)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}