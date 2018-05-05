#pragma once
#include <string>
using namespace std;


/**
* A class for PhoneBook application. This class will do all the phone-book options
*/

class PhoneBookClass
{
private:
	string FirstName; /**< String which stores first name of the contact >*/
	string LastName; /**< String which stores last name of the contact>*/
	string  MobileNo;/**< String which stores Mobile number of the contact>*/
	string Email;/**< String which stores Email Adress of the contact>*/

public:
	void DisplayContact();
	void AddContact(string new_FirstName, string new_LastName, string new_MobileNo, string new_Email);
	bool CheckContactExists();
	bool MatchContacts(string search);
	void DeletContacts();

public:
	PhoneBookClass();
	~PhoneBookClass();
};

