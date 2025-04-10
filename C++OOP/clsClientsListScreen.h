#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
class clsClientsListScreen :protected clsScreen
{
	static void _PrintClientRecordLine(clsBankClient Client) {
		cout << setw(8) << left << "" << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(12) << Client.PhoneNumber;
		cout << "| " << left << setw(20) << Client.Email;
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(12) << Client.AccountBalance;

	}
public:
	static void ShowClientsList() {
		vector<clsBankClient>vClients = clsBankClient::GetClientList();
		string SubTitle ="\t ("+ to_string(vClients.size()) + ") clients";
		_DrawScreenHeader("\t Client List Screen",SubTitle);
		
		cout << setw(10) << left << ""<<"\n\t________________________________________________________________________________________________\n";
		cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance" << endl;
		cout << setw(8) << left << ""<< "\n\t________________________________________________________________________________________________\n";
		if (vClients.size() == 0) {
			cout << "\nNo clients available in the system. ";
		}
		else {
			for (clsBankClient C : vClients)
			{
				 cout << endl;
				_PrintClientRecordLine(C);
			}
		}
		cout << "\n"<< setw(8) << left << "" <<"\n\t________________________________________________________________________________________________";
	}
};

