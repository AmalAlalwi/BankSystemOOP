#include <iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<fstream>
#include"clsBankClient.h";
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsMainScreen.h"
using namespace std;
static void PrintClientRecordBalanceLine(clsBankClient Client) {
	cout << "| " << left << setw(15) << Client.AccountNumber();
	cout << "| " << left << setw(40) << Client.FullName();
	cout << "| " << left << setw(12) << Client.AccountBalance;

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
	clsMainScreen::ShowMainScreen();
	return 0;
}

