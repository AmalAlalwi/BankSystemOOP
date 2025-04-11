#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
class clsUsersListScreen :protected clsScreen
{
	static void _PrintUserRecordLine(clsUser User) {
		cout << setw(8) << left << "" << "| " << left << setw(15) << User.UserName;
		cout << "| " << left << setw(20) << User.FullName();
		cout << "| " << left << setw(12) << User.PhoneNumber;
		cout << "| " << left << setw(20) << User.Email;
		cout << "| " << left << setw(10) << User.Password;
		cout << "| " << left << setw(12) << User.Permissions;

	}
public:
	static void ShowClientsList() {
		vector<clsUser>vUsers = clsUser::GetUsersList();
		string SubTitle = "\t (" + to_string(vUsers.size()) + ") users";
		_DrawScreenHeader("\t users List Screen", SubTitle);

		cout << setw(10) << left << "" << "\n\t__________________________________________________________________________________________________\n";
		cout << setw(8) << left << "" << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions" << endl;
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________________________\n";
		if (vUsers.size() == 0) {
			cout << "\nNo users available in the system. ";
		}
		else {
			for (clsUser User : vUsers)
			{
				cout << endl;
				_PrintUserRecordLine(User);
			}
		}
		cout << "\n" << setw(8) << left << "" << "\n\t________________________________________________________________________________________________";
	}
};

