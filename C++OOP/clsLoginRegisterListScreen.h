#pragma once
#include "clsScreen.h"
class clsLoginRegisterListScreen :protected clsScreen
{
	static void _PrintUserRecordLine(clsUser::stLoginRegisterRecord LoginRegisters) {
		cout << setw(8) << left << "" << "| " << left << setw(35) << LoginRegisters.SystemDate;
		cout << "| " << left << setw(20) << LoginRegisters.UserName;
		cout << "| " << left << setw(20) << LoginRegisters.Password;
		cout << "| " << left << setw(10) << LoginRegisters.Permissions;

	}
public:
	static void ShowLoginsRegisterScreen() {
		if (!CheckAccessRights(CurrentUser.pLoginRegister)) {
			return;
		}
		vector<clsUser::stLoginRegisterRecord>vLoinRegister = clsUser::GetLoginRegisterList();
		string SubTitle = "\t (" + to_string(vLoinRegister.size()) + ") users";
		_DrawScreenHeader("\t Login Register List Screen", SubTitle);
		cout << setw(10) << left << "" << "\n\t__________________________________________________________________________________________________\n\n";
		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions" << endl;
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________________________\n";
		if (vLoinRegister.size() == 0) {
			cout << "\nNo users available in the system. ";
		}
		else {
			for (clsUser::stLoginRegisterRecord Login : vLoinRegister)
			{
				cout << endl;
				_PrintUserRecordLine(Login);
			}
		}
		cout << "\n" << setw(8) << left << "" << "\n\t________________________________________________________________________________________________";
	}
};

