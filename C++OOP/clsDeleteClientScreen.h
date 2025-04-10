#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsDeleteClientScreen :protected clsScreen
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
private:
public:
	static void ShowDeleteClientScreen() {
		_DrawScreenHeader("\t Delete Client Screen");
	string AccountNumber = "";
	cout << "\nPlease Enter Client Account Number:";
	AccountNumber = clsInputValidate::ReadString();
	while (!clsBankClient::IsClientExist(AccountNumber)) {
		cout << "\nAccount number is not found,enter another one:";
		AccountNumber = clsInputValidate::ReadString();
	}
	clsBankClient Client = clsBankClient::Find(AccountNumber);
	_PrintClient(Client);
	cout << "Are you sure,you want to delete this client [y,n]?" << endl;
	char Answer = 'n';
	cin >> Answer;
	if (Answer == 'y' || Answer == 'Y') {
		if (Client.Delete()) {
			cout << "\nClient deleted successfully" << endl;
			_PrintClient(Client);
		}
		else cout << "\nError Client was't deleted." << endl;
	}
}
};

