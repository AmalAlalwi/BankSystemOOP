#include <iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<fstream>
#include"clsBankClient.h";
#include"clsInputValidate.h"
#include"clsUtil.h"
using namespace std;
void ReadClientInfo(clsBankClient& Client) {
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
void UpdateClient() {
	string AccountNumber = "";
	cout << "\nPlease Enter Client Account Number:";
	AccountNumber = clsInputValidate::ReadString();
	while (!clsBankClient::IsClientExist(AccountNumber)) {
		cout << "\nAccount number is not found,enter another one:";
		AccountNumber = clsInputValidate::ReadString();
	}
	clsBankClient Client = clsBankClient::Find(AccountNumber);
	Client.Print();
	cout << "\nUpdate client info";
	cout << "\n_____________________";
	ReadClientInfo(Client);
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
		break;
	}
	default:
		break;
	}

}
void AddNewClient() {
	string AccountNumber = "";
	cout << "\nPlease Enter Client Account Number:";
	AccountNumber = clsInputValidate::ReadString();
	while (clsBankClient::IsClientExist(AccountNumber)) {
		cout << "\nAccount number is already used,enter another one:";
		AccountNumber = clsInputValidate::ReadString();
	}
	clsBankClient AddNew = clsBankClient::GetAddNewClientObject(AccountNumber);
	ReadClientInfo(AddNew);
	clsBankClient::enSaveResult SaveResult;
	SaveResult = AddNew.Save();
	switch (SaveResult)
	{
	case clsBankClient::svFaildEmptyObject:
	{
		cout << "\nError account was not saved because it's empty";
		break;
	}
	case clsBankClient::svSucceeded: {
		cout << "\nAccount saved successfuly :-)\n";
		break;
	}
	case clsBankClient::svFaildAccountNumberExists: {
		cout << "\nError was not saved because it's already exists";
	}


	}

}
void DeleteClient() {
	string AccountNumber = "";
	cout << "\nPlease Enter Client Account Number:";
	AccountNumber = clsInputValidate::ReadString();
	while (!clsBankClient::IsClientExist(AccountNumber)) {
		cout << "\nAccount number is not found,enter another one:";
		AccountNumber = clsInputValidate::ReadString();
	}
	clsBankClient Client = clsBankClient::Find(AccountNumber);
	Client.Print();
	cout << "Are you sure,you want to delete this client [y,n]?" << endl;
	char Answer = 'n';
	cin >> Answer;
	if (Answer == 'y' || Answer == 'Y') {
		if (Client.Delete()) {
			cout << "\nClient deleted successfully" << endl;
			Client.Print();
		}
		else cout << "\nError Client was't deleted." << endl;
	}
}
void PrintClientRecordLine(clsBankClient Client) {
	cout << "| " << left << setw(15) << Client.AccountNumber();
	cout << "| " << left << setw(20) << Client.FullName();
	cout << "| " << left << setw(12) << Client.PhoneNumber;
	cout << "| " << left << setw(20) << Client.Email;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(12) << Client.AccountBalance;

}
void PrintClientRecordBalanceLine(clsBankClient Client) {
	cout << "| " << left << setw(15) << Client.AccountNumber();
	cout << "| " << left << setw(40) << Client.FullName();
	cout << "| " << left << setw(12) << Client.AccountBalance;

}
void ShowClientsList() {
	vector<clsBankClient>vClients = clsBankClient::GetClientList();
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") clients";
	cout << "\n________________________________________________________________________________________________\n";
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(20) << "Email";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n________________________________________________________________________________________________\n";
	if (vClients.size() == 0) {
		cout << "\nNo clients available in the system. ";
	}
	else {
		for (clsBankClient C : vClients)
		{
			cout << endl;
			PrintClientRecordLine(C);
		}
	}
	cout << "\n________________________________________________________________________________________________";
}
void ShowTotalBalance() {
	vector<clsBankClient>vClients = clsBankClient::GetClientList();
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") clients";
	cout << "\n________________________________________________________________________________________________\n";
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n________________________________________________________________________________________________\n";
	if (vClients.size() == 0) {
		cout << "\nNo clients available in the system. ";
	}
	else {
		for (clsBankClient C : vClients)
		{
			cout << endl;
			PrintClientRecordBalanceLine(C);
		}
	}
	cout << "\n________________________________________________________________________________________________\n";
	float TotalBaance = clsBankClient::GetTotalBalance();
	cout << "\t\t\t\t\tTotal Balance: " << TotalBaance << endl;
	cout << "\t\t\t\t\t( " << clsUtil::NumberToText(TotalBaance) << ")" << endl;

}
int main()
{

	ShowTotalBalance();
	return 0;
}

