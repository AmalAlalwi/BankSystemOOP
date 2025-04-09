#pragma once
#include <iostream>
using namespace std;
class clsPerson {
private:
	string _FirstName;
	string _LastName;
	string _Email, _PhoneNumber;
public:
	clsPerson(string FirstName, string LastName, string Email, string PhoneNumber) {
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_PhoneNumber = PhoneNumber;
	}
	void setFirstName(string FirstName) {
		_FirstName = FirstName;
	}
	string getFirstName() {
		return _FirstName;
	}
	void setLastName(string LastName) {
		_LastName = LastName;
	}
	string getLastName() {
		return _LastName;
	}
	void setEmail(string Email) {
		_Email = Email;
	}
	string getEmail() {
		return _Email;
	}
	void setPhoneNumber(string PhoneNumber) {
		_PhoneNumber = PhoneNumber;
	}
	string getPhoneNumber() {
		return _PhoneNumber;
	}
	__declspec(property(get = getFirstName, put = setFirstName))string FirstName;
	__declspec(property(get = getLastName, put = setLastName))string LastName;
	__declspec(property(get = getEmail, put = setEmail))string Email;
	__declspec(property(get = getPhoneNumber, put = setPhoneNumber))string PhoneNumber;
	string FullName() {
		return _FirstName + " " + _LastName;
	}
	void SendEmail(string Subject, string Body) {
		cout << "The message send successfuly to Email: " << _Email << endl;
		cout << "Subject: " << Subject << endl;
		cout << "Body: " << Body << endl;
	}
	void SendSMS(string Message) {
		cout << "SMS send successfuly to phone: " << _PhoneNumber << endl;
		cout << Message << endl;
	}

};

