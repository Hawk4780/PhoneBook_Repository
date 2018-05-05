#include "PhoneBookClass.h"
#include <iostream>
#include<iomanip>




/**
*@brief consturctor of the class phone book.
*/
PhoneBookClass::PhoneBookClass()
{

}
/**
* @brief Function to display contact information.
* This function will grants access to outside functions to access
* private varibales in the class to display there informations to user.
* @return Void
*/
void PhoneBookClass::DisplayContact()
{
	//std::cout << FirstName <<"\t" << LastName << "\t \t \t" << MobileNo << "\t \t" << Email <<std::endl;
	cout << "\t";
	cout << left << setw(20) << FirstName;
	cout << left << setw(20) << LastName;
	cout << left << setw(20) << MobileNo;
	cout << left << setw(20) << Email;
	cout << "\n" << endl;
}
/**
* @brief Function to add Contacts.
* This Function will gets data from outside function and will store them in class private variables.
* @param new_FirstName The name which user gives as the first name of the contact.
* @param new_LastName The name which user gives as the last name of the contact.
* @param new_MobileNo The mobile number which user gives as the mobile number of the contact.
* @param new_Email The email adress which user gives as the email of the contact.
* @return Void
*/
void PhoneBookClass::AddContact(string new_FirstName, string new_LastName, string new_MobileNo, string new_Email)
{
	FirstName = new_FirstName;
	LastName = new_LastName;
	MobileNo = new_MobileNo;
	Email = new_Email;
}
/**
* @brief Function to check existance of the contact.
* This will check whether the contact slot empty or not.
* @return 1 when contact slot empty and 0 when occupide.
*/
bool PhoneBookClass::CheckContactExists()
{
	if (FirstName == "")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/**
* @brief Function to match contacts.
* This will match user input name with stored contact names to see whether that contact available.
* @param search The user input first name or the second name of the contact.
* @return 1 when matching contact found and 0 when no match found.
*/
bool PhoneBookClass::MatchContacts(string search)
{
	if (FirstName == search || LastName == search)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/**
* @brief Function to deletcontacts.
* This function will set all class member variables to empty. In other words erace the contact informations.
* @return Void
*/
void PhoneBookClass::DeletContacts()
{
	FirstName = "";
	LastName = "";
	MobileNo = "";
	Email = "";

	cout << "Contact deleted successfully" << endl;
}

/**
*@brief destructor of the class phone book.
*/
PhoneBookClass::~PhoneBookClass()
{

}
