#pragma once
#include<iostream>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include"clsBankClient.h"
class clsDepositeScreen :protected clsScreen
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
	static void ShowDepositeScreen() {
		_DrawScreenHeader("\tDeposit Screen");
		string AccountNumber = "";
		cout << "\nPlease Enter Client Account Number:";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount number is not found,enter another one:";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		float Amount = 0;
		cout << "\nPlease enter deposit amount? ";
		Amount=clsInputValidate::ReadFloatNumber();
		char Answer = 'n';
		cout << "Are you sure you want perform this transaction?[y,n]\n";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Client.Deposit(Amount);
			cout << "Amount Deposite Successfully\n";
			cout << "New Balance :" << Client.AccountBalance<<endl;
		}
		else {
			cout << "Operation was canceled \n";
		}
	}
};

