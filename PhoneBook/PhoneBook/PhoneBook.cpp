// PhoneBook.cpp : Defines the entry point for the console application.
//

/**
* @file PhoneBook.cpp
* @brief This is where all the functions are integrated and excuted.
*/

#include "stdafx.h"
#include "Userinterface.h"
#include "PhoneBookClass.h"
#include"MenuSelectionSwitch.h"
#include <iostream>
#include<iomanip>
#include <string>
using namespace std;



PhoneBookClass Contacts[100];/**<This create 100 empty contacts*/

string temp_Firstname;/**<This stores user input First name tempo contacts*/
string temp_Lastname;/**<This create 100 empty contacts*/
string temp_MobileNo;/**<This create 100 empty contacts*/
string temp_Email;/**<This create 100 empty contacts*/

int FoundContactid = 0;/**<This varibale will keep track of found contacts array number*/




					   /**
					   * @brief This will add some inital contacts to test the program behaviour.
					   * In a forloop assigns values to temp variables and then passes it to the class public function.
					   * @return Void
					   */
void AddInitialContacts()
{
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			temp_Firstname = "Akram";
			temp_Lastname = "Mohamed";
			temp_MobileNo = "0778264896";
			temp_Email = "akram.mohomed0@yahoo.com";
			Contacts[i].AddContact(temp_Firstname, temp_Lastname, temp_MobileNo, temp_Email);
		}
		else if (i == 1)
		{
			temp_Firstname = "Tharindi";
			temp_Lastname = "Ginige";
			temp_MobileNo = "0775298559";
			temp_Email = "Tharindi.ginige789@gmail.com";
			Contacts[i].AddContact(temp_Firstname, temp_Lastname, temp_MobileNo, temp_Email);
		}
		else if (i == 2)
		{
			temp_Firstname = "Hamilton";
			temp_Lastname = "Lewis";
			temp_MobileNo = "+9665048967534";
			temp_Email = "Lewis.Hamilton@gmail.com";
			Contacts[i].AddContact(temp_Firstname, temp_Lastname, temp_MobileNo, temp_Email);
		}
		else if (i == 3)
		{
			temp_Firstname = "DJ";
			temp_Lastname = "Watson";
			temp_MobileNo = "+1127756809851";
			temp_Email = "Watson.DJ@yahoo.com";
			Contacts[i].AddContact(temp_Firstname, temp_Lastname, temp_MobileNo, temp_Email);
		}
		else if (i == 4)
		{
			temp_Firstname = "Mahinda";
			temp_Lastname = "Rajapaksha";
			temp_MobileNo = "0770754159";
			temp_Email = "Mahinda.Rajapaksha123@yahoo.com";
			Contacts[i].AddContact(temp_Firstname, temp_Lastname, temp_MobileNo, temp_Email);
		}

	}

}
/**
* @brief When ever user wants to add contacts this function is called.
* First of all this function checks for empty contact slot in a for loop.
* When empty slot available add those contact informations to it.
* @return Void
*/
void AddContacts()
{
	for (int i = 0; i < 100; i++)
	{
		if (Contacts[i].CheckContactExists() == 1)
		{
			system("cls");
			cout << "Enter First name" << endl;
			cin >> temp_Firstname;
			system("cls");

			cout << "Enter Last name" << endl;
			cin >> temp_Lastname;
			system("cls");

			cout << "Enter Mobile number" << endl;
			cin >> temp_MobileNo;
			system("cls");

			cout << "Enter Email" << endl;
			cin >> temp_Email;
			system("cls");

			Contacts[i].AddContact(temp_Firstname, temp_Lastname, temp_MobileNo, temp_Email);

			system("cls");
			cout << "\t \t \t \t" << left << setw(50) << "Newly added Contact";
			cout << "\n" << endl;
			cout << "\t";
			cout << left << setw(20) << "First Name";
			cout << left << setw(20) << "Last Name";
			cout << left << setw(20) << "Mobile Number";
			cout << left << setw(20) << "Email";
			cout << "\n" << endl;
			Contacts[i].DisplayContact();
			system("pause");
			break;
		}
	}
}
/**
* @brief this function is to display contacts.
* First of all this function filter out empty contacts and displays contact information.
* @return Void
*/
void DisplayContacts()
{
	system("cls");
	cout << "\t";
	cout << left << setw(20) << "First Name";
	cout << left << setw(20) << "Last Name";
	cout << left << setw(20) << "Mobile Number";
	cout << left << setw(20) << "Email";
	cout << "\n" << endl;

	for (int i = 0; i < 100; i++)
	{
		if (Contacts[i].CheckContactExists() == 1)
		{

		}
		else
		{
			Contacts[i].DisplayContact();
		}
	}
}
/**
* @brief Function to search stored contacts.
* Users can search contacts using first name or last name.
* When matching contact found wil display it.
* Or tells user to try diffrent name to enter.
* @param contactFound when contact found this will be true.
* @param searchAgain when user wants to search again this will be true.
* @return Void
*/
void SearchContacts()
{
	bool contactFound = false;
	bool searchAgain = false;

	do
	{
		searchAgain = false;
		contactFound = false;
		string userSearch;
		cout << "Please Enter First Name or Second Name of the contact" << endl;
		cin >> userSearch;

		for (int i = 0; i < 100; i++)
		{
			if (Contacts[i].MatchContacts(userSearch) == 1)
			{
				system("cls");
				cout << "\t";
				cout << left << setw(20) << "First Name";
				cout << left << setw(20) << "Last Name";
				cout << left << setw(20) << "Mobile Number";
				cout << left << setw(20) << "Email";
				cout << "\n" << endl;

				Contacts[i].DisplayContact();
				contactFound = true;
				FoundContactid = i;
				system("pause");
			}
			else if (i == 99 && contactFound == false)
			{
				system("cls");
				cout << "No Contacts were found; ";
				cout << "Would you like to search again ?";
				cout << "\n" << endl;
				cout << "\t \t Enter (Y) to Search again, (N) to Go back" << endl;

				char userChoice;
				cin >> userChoice;
				if (userChoice == 'y' || userChoice == 'Y')
				{
					searchAgain = true;
				}

			}
		}
	} while (searchAgain == true);
}
/**
* @brief Function to delet contacts.
* When ever user slects to delet option from main menu this function is called.
* @param userChoice this will store user input whether he want delet the contact or not
* @return Void
*/
void DeleteContact()
{
	char userChoice;
	system("cls");
	SearchContacts();
	cout << " " << endl;
	cout << "\t Would you like to delet this contact (Y/N) ?" << endl;
	cin >> userChoice;

	if (userChoice == 'Y' || userChoice == 'y')
	{
		Contacts[FoundContactid].DeletContacts();
	}
}


/**
* @brief main function.
* First of all this adds initial contacts.
* Then in a do while loop displays main menu and excutes functions according to user
* choice.
* @return 0
*/
int main(int argc, char* argv[])
{
	AddInitialContacts();
	do
	{
		system("cls");
		MainMenue();
		MenuSelection();
	} while (exit() == 0);

	return 0;

}

