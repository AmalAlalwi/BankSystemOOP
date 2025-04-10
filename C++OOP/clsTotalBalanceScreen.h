#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include "clsUtil.h"
class clsTotalBalanceScreen :protected clsScreen
{
	static void PrintClientRecordBalanceLine(clsBankClient Client) {
		cout <<setw(25)<<left<< "" << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(40) << Client.FullName();
		cout << "| " << left << setw(12) << Client.AccountBalance;

	}
public:
	static void ShowTotalBalancesScreen() {
		vector<clsBankClient>vClients = clsBankClient::GetClientList();
		string SubTitle = "\t (" + to_string(vClients.size()) + ") clients";
		_DrawScreenHeader("\t Client List Screen", SubTitle);
		cout << setw(25) << left << "" << "\n\t________________________________________________________________________________________________\n\n";
		cout <<setw(24) << left << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\n\t________________________________________________________________________________________________\n";

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
		cout << setw(25) << left << "" << "\n\t________________________________________________________________________________________________\n";
		float TotalBaance = clsBankClient::GetTotalBalance();
		cout << "\t\t\t\t\tTotal Balance: " << TotalBaance << endl;
		cout << "\t\t\t\t\t( " << clsUtil::NumberToText(TotalBaance) << ")" << endl;
	}
};

