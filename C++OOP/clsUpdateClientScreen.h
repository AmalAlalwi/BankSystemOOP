#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsUpdateClientScreen :protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client) {
		cout << "\nEnter First Name:";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name:";
		Client.LastName = clsInputValidate::ReadString();
		cout << "\nEnter PinCode:";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter Phone:";
		Client.PhoneNumber = clsInputValidate::ReadString();
		cout << "\nEnter Email:";
		Client.Email = clsInputValidate::ReadString();
		cout << "\nEnter Account Balance:";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}
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
	static void ShowUpdateClientScreen() {
		_DrawScreenHeader("\tUpdate Client Screen");
		string AccountNumber = "";
	    cout << "\nPlease Enter Client Account Number:";
	    AccountNumber = clsInputValidate::ReadString();
	    while (!clsBankClient::IsClientExist(AccountNumber)) {
	    	cout << "\nAccount number is not found,enter another one:";
	    	AccountNumber = clsInputValidate::ReadString();
	    }
	    clsBankClient Client = clsBankClient::Find(AccountNumber);
	    _PrintClient(Client);
	    cout << "\nUpdate client info";
	    cout << "\n_____________________";
	    _ReadClientInfo(Client);
	    clsBankClient::enSaveResult SaveResult;
	    SaveResult = Client.Save();
	    switch (SaveResult)
	    {
	    case clsBankClient::svFaildEmptyObject:
	    {
	    	cout << "\nError account was not saved because it's empty";
	    	break;
	    }
	    case clsBankClient::svSucceeded: {
	    	cout << "\nAccount saved successfuly :-)\n";
			_PrintClient(Client);
	    	break;
	    }
	    default:
	    	break;
	    }
	    }
};

