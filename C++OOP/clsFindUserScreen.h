#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsFindUserScreen :protected clsScreen
{
	static 	void _PrintUser(clsUser User) {
		cout << "Info: \n";
		cout << "___________________________________\n";
		cout << "FirstName:   " << User.FirstName << endl;
		cout << "LastName:    " << User.LastName << endl;
		cout << "FullName:    " << User.FullName() << endl;
		cout << "Email:       " << User.Email << endl;
		cout << "PhoneNumber: " << User.PhoneNumber << endl;
		cout << "UserName " << User.UserName << endl;
		cout << "Password " << User.Password << endl;
		cout << "Permissions " << User.Permissions << endl;
		cout << "___________________________________\n";
	}
public :
	static void ShowFindUserScreen() {
		_DrawScreenHeader("\t Find User Screen");
		string UserName = "";
		cout << "\nPlease Enter Username:";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName)) {
			cout << "\nUsername is not found,enter another one:";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		if (User.IsEmpty()) {
			cout << "User Not Found :-(\n";
		}
		else cout << "User Found :-)\n"; {
			_PrintUser(User);
		}
	}
};

