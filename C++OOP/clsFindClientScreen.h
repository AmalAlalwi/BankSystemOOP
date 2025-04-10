#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsFindClientScreen :protected clsScreen
{
	static 	void _PrintClient(clsBankClient Client) {
		cout << "Info: \n";
		cout << "___________________________________\n";
		cout << "AccountNumber " << Client.AccountNumber() << endl;
		cout << "FirstName:   " << Client.FirstName << endl;
		cout << "LastName:    " << Client.LastName << endl;
		cout << "FullName:    " << Client.FullName() << endl;
		cout << "Email:       " << Client.Email << endl;
		cout << "PhoneNumber: " << Client.PhoneNumber << endl;
		cout << "PinCode:     " << Client.PinCode << endl;
		cout << "AccountBalance " << Client.AccountBalance << endl;
		cout << "___________________________________\n";
	}
public:
	static void ShowFindClientScreen() {
		
		_DrawScreenHeader("\tFind Client Screen");
		string AccountNumber = "";
		cout << "\nPlease Enter Client Account Number:";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount number is not found,enter another one:";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		if (Client.IsEmpty()) {
			cout << "Client Not Found :-(\n";
		}
		else cout << "Client Found :-)\n";
		_PrintClient(Client);
	}
};

